#include <vector>
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
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 2e5+5;
int n,m;
vector<PII> v[MAXN];
int r[MAXN], val[MAXN];
bool z[MAXN], has[MAXN], good;
US<int> w,wait[MAXN];
vector<PII> tmp;

void dfs(int s) {
    z[s] = 1;
    if (!has[r[s]]) w.insert(r[s]), good = 1;
    FORX(u,v[s]) {
        if (z[u.F]) continue;
        if (has[u.S]) {
            // if (tmp.count(u.F)) tmp.erase(u.F);
            // if (!v[u.F].empty() && wait[v[u.F][0].S].count(u.F)) {
            //     FORX(y,v[u.F]) wait[y.S].erase(u.F);
            // }
            dfs(u.F);
        }
        else tmp.PB({u.F, u.S});
    }
}

int solve(int start) {
    FORX(u,v[start]) wait[u.S].insert(start);
    w.insert(r[start]);
    has[r[start]] = 1;
    while (true) {
        vector<int> tmpw;
        FORX(u,w) tmpw.PB(u);
        w.clear();
        US<int> toclr;
        FORX(u,tmpw) FORX(y,wait[u]) dfs(y), toclr.insert(y);
        FORX(u,toclr) FORX(y,v[u]) if (wait[y.S].count(u)) wait[y.S].erase(u);
        FORX(u,w) has[u] = 1;
        FORX(u,tmp) {
            if (z[u.F]) continue;
            wait[u.S].insert(u.F);
        }
        tmp.clear();
        if (!good) break;
        good = 0;
    }
    int ans = 0;
    FOR(i,0,n) ans += z[i];
    return ans;
}

void reset() {
    FOR(i,0,n) z[i] = has[i] = 0;
    good = 0;
    FOR(i,0,n) wait[i].clear();
    tmp.clear();
    w.clear();
}

std::vector<int> find_reachable(std::vector<int> R, std::vector<int> U, std::vector<int> V, std::vector<int> C) {
	n = R.size(), m = U.size();
    FOR(i,0,n) r[i] = R[i];
    FOR(i,0,m) v[U[i]].PB({V[i],C[i]}), v[V[i]].PB({U[i],C[i]});
    int res = INF;
    FOR(i,0,n) {
        reset();
        val[i] = solve(i);
        res = min(res, val[i]);
    }
    vector<int> resv(n);
    FOR(i,0,n) if (val[i] == res) resv[i] = 1;
    return resv;
}
