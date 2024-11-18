#include "simurgh.h"
#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int(1e9+7)
#define ln '\n' 
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,n,s) for (int i = n; i > s; i--)
#define FORX(u, arr) for (auto u : arr)
#define PB push_back
#define in(v,x) (v.find(x) != v.end())
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 1e5+5;
int n,m;
int p[MAXN], sz[MAXN];
vector<int> e, comp[MAXN];
vector<PII> v[MAXN], edges;
bool z[MAXN], ze[MAXN], res[MAXN], done[MAXN]; // ze = visited edge, done = processed edge
vector<int> toclr;

int finds(int x) {
    if (p[x] != x) p[x] = finds(p[x]);
    return p[x];
}

void unite(int a, int b, int idx) {
    a = finds(a);
    b = finds(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
        e.PB(idx);
    }
}

void reset() {
    FOR(i,0,n) z[i] = 0, p[i] = i, sz[i] = 1;
    FORX(u,toclr) ze[u] = 0;
    toclr.clear();
    e.clear();
    FOR(i,0,n) comp[i].clear();
}

void dfs(int s, int num, int src) {
    if (z[s]) return;
    z[s] = 1;
    FORX(u,v[s]) {
        if (u.F == src) {
            ze[u.S] = 1;
            toclr.PB(u.S);
            comp[num].PB(u.S);
        }
        else dfs(u.F,num,src);
    }
}

void print(int s) {
    cout << "s: " << s << "| e: ";
    FORX(y,e) cout << y << " ";
    cout << ln;
}

void solve(int s) {
    reset(); // common w reset
    int cnt = 0;
    // FOR(i,0,m) cout << ze[i] << " ";
    // cout << ln;
    FORX(u,v[s]) {
        if (ze[u.S]) continue;
        ze[u.S] = 1;
        toclr.PB(u.S);
        dfs(u.F,cnt++,s);
    }
    FOR(j,0,m) {
        if (edges[j].F != s && edges[j].S != s) unite(edges[j].F,edges[j].S,j);
    }
    // cout << "s: " << s << ln;
    // FOR(i,0,cnt) {
    //     cout << i << ": ";
    //     FORX(u,comp[i]) cout << u << " ";
    //     cout << ln;
    // }
    FOR(i,0,cnt) {
        // if (comp[i].empty()) continue;
        FOR(j,0,cnt) if (j != i) e.PB(comp[j][0]);
        vector<int> le,gr;
        int orig = -INF, start = 1, isgold = -1;
        FORX(u,comp[i]) {
            if (done[u]) {
                e.PB(u);
                // print(s);
                orig = count_common_roads(e);
                e.pop_back();
                isgold = res[u];
                start = 0;
                break;
            }
        }
        if (isgold == -1) {
            e.PB(comp[i][0]); le.PB(comp[i][0]);
            // print(s);
            orig = count_common_roads(e);
            e.pop_back();
        }
        // int start = 0, cn = comp[i].size();
        // while (start < cn && done[comp[i][start]]) start++;
        // start = max(0,start-1);
        // if (start >= cn) continue;
        // e.PB(comp[i][start]); le.PB(comp[i][start]);
        // cout << "s: " << s << "| e: ";
        // FORX(y,e) cout << y << " ";
        // cout << ln;
        // int orig = count_common_roads(e);
        // e.pop_back();
        bool sm = 0;
        FOR(k,start,comp[i].size()) {
            int u = comp[i][k];
            if (done[u]) continue;
            e.PB(u);
            // print(s);
            int cur = count_common_roads(e);
            e.pop_back(); // reset single edge
            if (orig < cur) sm = 1, gr.PB(u);
            else if (orig == cur) le.PB(u);
        }
        if (sm || isgold == 0) FORX(y,gr) res[y] = 1;
        else FORX(y,le) res[y] = 1;
        FOR(j,0,cnt-1) e.pop_back(); // reset component edges
    }
    FORX(u,v[s]) done[u.S] = 1;
}

std::vector<int> find_roads(int N, std::vector<int> U, std::vector<int> V) {
    n = N; m = U.size();
    FOR(i,0,m) {
        edges.PB({U[i],V[i]});
        v[U[i]].PB({V[i],i}), v[V[i]].PB({U[i],i});
    }
    FOR(i,0,n) solve(i);
    vector<int> resv;
    FOR(i,0,m) if (res[i]) resv.PB(i);
    // cout << ln;
    // FORX(u,resv) cout << u << " ";
    // cout << ln;
    return resv;
    // cout << "xd\n";
    // FORX(u,res) cout << u << " ";
    // cout << ln;
}
