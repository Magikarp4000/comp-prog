#include "fish.h"
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
 
const int MAXN = 3e3+5, MAXX = 15;
int n,m;
int dp[MAXN][MAXN], g[MAXN][MAXN], p[MAXN][MAXN];
int dp1[MAXN][MAXN], dp2[MAXN][MAXN], dp3[MAXN][MAXN], dp4[MAXN][MAXN], dp5[MAXN][MAXN];
 
long long max_weights(int32_t N, int32_t M, std::vector<int32_t> X, std::vector<int32_t> Y, std::vector<int32_t> W) {
    n = N; m = M;
    FOR(i,0,m) {
        g[X[i]][Y[i]] = W[i]*1LL;
    }
    FOR(i,1,n+1) {
        FOR(j,1,n+1) {
            p[i][j] = p[i][j-1]+g[i-1][j-1];
        }
    }
    // FORR(j,yn+1,0) {
    //     FOR(i,1,n+1) cout << p[i][j] << " ";
    //     cout << ln;
    // }
    // cout << ln;
    FOR(i,0,n+1) {
        FOR(j,0,n+1) {
            dp2[i][j] = -LLINF;
        }
    }
    if (n > 1) {
        dp3[1][n] = p[2][n];
        FORR(j,n-1,-1) dp3[1][j] = max(dp3[1][j+1], p[2][j]);
    }
    FOR(i,2,n+1) {
        FOR(j,0,n+1) {
            dp[i][j] = dp2[i-1][j]+p[i-1][j];
            dp1[i][j] = dp3[i-1][j]-p[i][j];
            int zero = max(dp4[i-1][n], dp5[i-1][n]+p[i-1][j]);
            dp[i][j] = max(dp[i][j], zero);
            dp1[i][j] = max(dp1[i][j], zero);
        }
        dp2[i][0] = dp[i][0];
        dp4[i][0] = dp5[i][0] = max(dp[i-1][0], dp1[i-1][0]);
        FOR(j,1,n+1) {
            dp2[i][j] = max(dp2[i][j-1], dp[i][j]-p[i][j]);
            dp4[i][j] = max(dp4[i][j-1], max(dp[i-1][j], dp1[i-1][j])+p[i][j]);
            dp5[i][j] = max(dp5[i][j-1], max(dp[i-1][j], dp1[i-1][j]));
        }
        dp3[i][n] = dp[i][n]+p[i+1][n];
        FORR(j,n-1,-1) {
            dp3[i][j] = max(dp3[i][j+1], max(dp[i][j], dp1[i][j])+p[i+1][j]);
        }
    }
    // cout << ln;
    // FORR(j,yn+1,-1) {
    //     FOR(i,1,n+1) cout << max(dp[i][j], dp1[i][j]) << " ";
    //     cout << ln;
    // }
    int res = -LLINF;
    FOR(j,0,n+1) {
        res = max(res, max(dp[n][j], dp1[n][j]));
    }
    return res;
}