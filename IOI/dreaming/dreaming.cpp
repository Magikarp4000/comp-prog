#include "dreaming.h"
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
#define int long long

const int MAXN = 1e5+5;
int n,m,l;
vector<PII> v[MAXN];
int dp[MAXN], dp1[MAXN], dp2[MAXN];
bool z[MAXN];
vector<int> vis;

void dfs1(int s, int pa) {
    z[s] = 1;
    vis.PB(s);
    int idx = -1;
    FORX(u,v[s]) {
        if (u.F == pa) continue;
        dfs1(u.F,s);
        if (dp[u.F]+u.S > dp[s]) {
            dp[s] = dp[u.F]+u.S;
            idx = u.F;
        }
    }
    FORX(u,v[s]) if (u.F != idx && u.F != pa) dp1[s] = max(dp1[s], dp[u.F]+u.S);
}

void dfs2(int s, int pa) {
    FORX(u,v[s]) {
        if (u.F == pa) continue;
        int c = dp[u.F]+u.S == dp[s] ? dp1[s] : dp[s];
        dp2[u.F] = max(dp2[s],c)+u.S;
        dfs2(u.F,s);
    }
}

int32_t travelTime(int32_t N, int32_t M, int32_t L, int32_t A[], int32_t B[], int32_t T[]) {
    n = N, m = M, l = L;
    FOR(i,0,m) v[A[i]].PB({B[i],T[i]*1LL}), v[B[i]].PB({A[i],T[i]*1LL});
    vector<int> vals;
    FOR(i,0,n) {
        if (z[i]) continue;
        z[i] = 1;
        vis.clear();
        dfs1(i,-1);
        dfs2(i,-1);
        int ans = LLINF;
        FORX(u,vis) ans = min(ans, max(dp[u], dp2[u]));
        vals.PB(ans);
    }
    sort(ALL(vals), greater<int>());
    int res = -LLINF;
    FOR(i,0,n) res = max(res, max(dp[i], dp2[i]));
    if (vals.size() == 1) return max(res, vals[0]);
    if (vals.size() == 2) return max(res, vals[0]+vals[1]+L);
    return max(res, max(vals[0]+vals[1]+L, vals[1]+vals[2]+2*L));
}
