#include "circuit.h"
#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1000002022)
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
 
const int MAXN = 1e5+5;
int n,m;
vector<int> adj[MAXN];
int z[MAXN];
int dp0[MAXN], dp1[MAXN], cnt[MAXN];
 
void dfs(int s) {
    int sz = adj[s].size();
    if (sz == 0) {
        dp1[s] = z[s];
        dp0[s] = z[s]^1LL;
        cnt[s] = 1LL;
        return;
    }
    FORX(u,adj[s]) {
        dfs(u);
    }
    vector<int> v;
    FORX(u,adj[s]) v.PB(u);
    vector<vector<int>> dp(sz+1,vector<int>(sz+1,0LL));
    dp[0][0] = 1LL;
    FOR(j,1,sz+1) dp[0][j] = (dp[0][j-1]*dp0[v[j-1]])%INF;
    FOR(i,1,sz+1) {
        FOR(j,1,sz+1) {
            dp[i][j] = ((dp[i][j-1]*dp0[v[j-1]])%INF + (dp[i-1][j-1]*dp1[v[j-1]])%INF)%INF;
        }
    }
    // if (s == 0) {
    //     FOR(i,0,sz+1) {
    //         FOR(j,0,sz+1) cout << dp[i][j] << " ";
    //         cout << ln;
    //     }
    // }
    int total = sz;
    FORX(u,adj[s]) total = (total*cnt[u])%INF;
    int dpsum = 0LL;
    FOR(i,1,sz+1) dpsum = (dpsum+(dp[i][sz]*i)%INF)%INF;
    dp1[s] = dpsum;
    dp0[s] = (total-dpsum+INF)%INF;
    cnt[s] = total;
}
 
void init(int32_t N, int32_t M, std::vector<int32_t> P, std::vector<int32_t> A) {
    n = N; m = M;
    FOR(i,1,int32_t(P.size())) adj[P[i]].PB(i);
    FOR(i,0,int32_t(A.size())) z[n+i] = A[i];
}
 
int32_t count_ways(int32_t L, int32_t R) {
    FOR(i,L,R+1) z[i] ^= 1;
    dfs(0);
    // FOR(i,0,n+m) cout << dp1[i] << " ";
    // cout << ln;
    // FOR(i,0,n+m) cout << dp0[i] << " ";
    // cout << ln;
    return dp1[0];
}