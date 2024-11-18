#include "highway.h"
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
#define int long long

struct Edge {
    int x,y,depth;
};

const int MAXN = 9e4+5;
int n,m;
vector<PII> v[MAXN];
vector<int32_t> w;
vector<Edge> e;
int d[MAXN];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        int to = u.F, idx = u.S;
        if (to == pa) continue;
        d[to] = d[s]+1;
        e[idx].depth = d[to];
        if (e[idx].y != to) swap(e[idx].x, e[idx].y);
        dfs(to,s);
    }
}

void find_pair(int32_t N, std::vector<int32_t> U, std::vector<int32_t> V, int32_t A, int32_t B) {
    n = N; m = U.size();
    FOR(i,0,m) {
        v[U[i]].PB({V[i],i});
        v[V[i]].PB({U[i],i});
        e.PB({U[i],V[i],-1LL});
    }
    dfs(0,-1);
    // cout << "ahahaha" << ln;
    FOR(i,0,m) w.PB(0);
    int orig = ask(w)/A;
    int ex = (orig-1)*A;
    vector<int> p;
    FOR(i,0,m) if (e[i].depth == orig) p.PB(i);
    int pn = p.size();
    int l = 0, r = pn-1;
    // cout << orig << " " << ex << ln;
    // FORX(u,p) cout << u << " ";
    // cout << ln;
    // answer(0,n-1);
    // return;
    while (l < r) {
        FORX(u,p) w[u] = 0;
        int mid = (l+r)/2;
        FOR(i,l,mid+1) w[p[i]] = 1;
        int val = ask(w)-ex;
        if (val == A) l = mid+1;
        else r = mid;
    }
    int32_t res = e[p[l]].y;
    answer(0,res);
}
