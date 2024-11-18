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

const int MAXN = 3e5+10;
int n,m;
map<int,int> p[MAXN];
UM<int,int> dp[2], dp1[2], dp2;
map<int,int> dp3;
int dp4, dp5;
vector<PII> v[MAXN], v1[MAXN], v2[MAXN], v3[MAXN];

long long max_weights(int32_t N, int32_t M, std::vector<int32_t> X, std::vector<int32_t> Y, std::vector<int32_t> W) {
    n = N; m = M;
    FOR(i,0,m) {
        v[X[i]+1].PB({Y[i]+1,W[i]});
    }
    FOR(i,1,n+1) v[i].PB({0LL,0LL});
    FOR(i,1,n+2) {
        FORX(u,v[i]) v2[i].PB(u), v1[i].PB(u), v3[i].PB(u);
        FORX(u,v[i+1]) v2[i].PB({u.F,0LL}), v1[i].PB({u.F,0LL});
        FORX(u,v[i-1]) v2[i].PB({u.F,0LL}), v3[i].PB({u.F,0LL});
    }
    FOR(i,0,n+2) {
        sort(ALL(v[i]));
        sort(ALL(v1[i]));
        sort(ALL(v2[i]));
        sort(ALL(v3[i]));
    }
    FOR(i,1,n+2) {
        int cur = 0LL;
        FORX(u,v2[i]) {
            p[i][u.F] = cur+u.S;
            cur += u.S;
        }
    }
    FORX(u,v2[1]) dp2[u.F] = 0LL;
    int cur3 = -LLINF, v2n = v2[1].size();
    auto it = p[2].end();
    it--;
    FORR(x,v2n-1,-1) {
        int j = v2[1][x].F;
        PII rn = *it;
        while (j < rn.F) {
            it--;
            rn = *it;
        }
        dp3[j] = max(cur3, rn.S);
        cur3 = dp3[j];
    }
    // cout << "1: ";
    // FORX(u,v2[1]) cout << u.F << " ";
    // cout << ln;
    FOR(i,2,n+1) {
        int pm = 0LL, pm1 = 0LL, dm2 = 0LL;
        auto it1 = dp3.end();
        it1--;
        FORX(u,v2[i]) {
            int j = u.F;
            pm = max(pm,p[i][j]);
            pm1 = max(pm1,p[i-1][j]);
            dm2 = max(dm2, dp2[j]);
            PII rn = *it1;
            while (j < rn.F) {
                it1--;
                rn = *it1;
            }
            dp[1][j] = dm2+pm1;
            dp1[1][j] = rn.S-pm;
            int zero = max(dp4, dp5+pm1);
            dp[1][j] = max(dp[1][j], zero);
            dp1[1][j] = max(dp1[1][j], zero);
        }
        dp2.clear(); dp3.clear();
        int cur2 = -LLINF;
        dp4 = dp5 = 0LL;
        pm = 0LL;
        // cout << i << ": ";
        int dm = 0LL, dm0 = 0LL, dm01 = 0LL;
        FORX(u,v2[i]) {
            int j = u.F;
            // cout << "(" << j << "," << max(dp[1][j],dp1[1][j]) << ") ";
            dm = max(dm, dp[1][j]);
            pm = max(pm, p[i][j]);
            // dm0 = max(dm0, dp[0][j]);
            // dm01 = max(dm01, dp1[0][j]);
            dp2[j] = max(cur2, dm-pm);
            cur2 = dp2[j];
            // if (!p[i-1].count(j)) continue;
            dp4 = max(dp4, max(dp[0][j],dp1[0][j])+pm);
            dp5 = max(dp5, max(dp[0][j],dp1[0][j]));
        }
        // cout << ln;
        int vn = v2[i].size();
        int cur3 = -LLINF;
        auto it = p[i+1].end();
        it--;
        FORR(x,vn-1,-1) {
            int j = v2[i][x].F;
            PII rn = *it;
            while (j < rn.F) {
                it--;
                rn = *it;
            }
            dp3[j] = max(cur3, max(dp[1][j], dp1[1][j])+rn.S);
            cur3 = dp3[j];
        }
        // FORR(x,vn-1,-1) {
        //     int j = v2[i][x].F;
        //     pm2 = max(pm2, p[i+1][j]);
        //     dp3[j] = max(cur3, max(dp[1][j], dp1[1][j])+pm2);
        //     cur3 = dp3[j];
        // }
        dp[0].clear(); dp1[0].clear();
        FORX(u,dp[1]) dp[0].insert(u);
        FORX(u,dp1[1]) dp1[0].insert(u);
        dp[1].clear(); dp1[1].clear();
    }
    int res = -LLINF;
    FORX(u,v2[n]) {
        int j = u.F;
        res = max(res, max(dp[0][j], dp1[0][j]));
    }
    return res;
}
