#include "split.h"
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
int n,m,a,b,c;
vector<int> v[MAXN], v1[MAXN], res, cur;
int p[MAXN], sz[MAXN], cnt;
bool z[MAXN], bad[MAXN];

void dfs(int s, int pa) {
    z[s] = 1;
    FORX(u,v[s]) {
        if (z[u]) continue;
        v1[s].PB(u);
        v1[u].PB(s);
        dfs(u,s);
        // p[u] = s;
        // sz[s] += sz[u];
        
    }
}

void dfs3(int s, int pa) {
    sz[s] = 1;
    FORX(u,v1[s]) {
        if (u == pa) continue;
        p[u] = s;
        dfs3(u,s);
        sz[s] += sz[u];
    }
}

void dfs1(int s, int pa, int ub, int idx) {
    if (cnt < ub) {
        cur.PB(s);
        cnt++;
    }
    if (cnt >= ub) return;
    FORX(u,v1[s]) if (u != pa) dfs1(u,s,ub,idx);
}

void dfs2(int s, int pa, int ub) {
    if (cnt < ub) {
        cur.PB(s);
        cnt++;
    }
    if (cnt >= ub) return;
    FORX(u,v1[s]) if (u != pa && !res[u]) dfs2(u,s,ub);
}

bool check(int s, int pa, PII h[3]) {
    cnt = 0;
    cur.clear();
    dfs2(s,pa,h[1].F);
    if (cnt == h[1].F) {
        FORX(u,cur) res[u] = h[1].S;
        FOR(i,0,n) if (!res[i]) res[i] = h[2].S;
        return 1;
    }
    return 0;
}

vector<int> find_split(int N, int A, int B, int C, vector<int> P, vector<int> Q) {
    n = N, a = A, b = B, c = C, m = P.size();
    PII h[3] = {{a,1}, {b,2}, {c,3}};
    sort(h,h+3);
    vector<int> noob(n,0);
    FOR(i,0,m) {
        v[P[i]].PB(Q[i]);
        v[Q[i]].PB(P[i]);
    }
    res.resize(n,0);
    cur.resize(n,0);
    dfs(0,-1);
    FOR(i,0,n) {
        res[i] = sz[i] = 0;
        p[i] = -1;
    }
    dfs3(0,-1);
    int mi = INF, x = -1;
    FOR(i,0,n) {
        if (sz[i] < h[0].F) continue;
        bool ok = 1;
        FORX(u,v1[i]) if (u != p[i] && sz[u] >= h[0].F) ok = 0;
        if (ok && sz[i] < mi) {
            mi = sz[i];
            x = i;
        }
    }
    if (p[x] == -1 || !(sz[x] >= h[0].F && n-sz[x] >= h[0].F)) return noob;
    cnt = 0;
    cur.clear();
    dfs1(x,p[x],h[0].F,h[0].S);
    FORX(u,cur) res[u] = h[0].S;
    if (check(p[x],x,h)) return res;
    cnt = 0;
    cur.clear();
    FOR(i,0,n) res[i] = 0;
    dfs1(p[x],x,h[0].F,h[0].S);
    FORX(u,cur) res[u] = h[0].S;
    if (check(x,p[x],h)) return res;
    return noob;
}
