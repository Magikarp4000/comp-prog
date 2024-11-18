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
vector<PII> p[MAXN], v[MAXN], v2[MAXN];
vector<int> v1[MAXN];
vector<PII> dp[MAXN], dp1[MAXN], dp2[MAXN], dp3[MAXN];
int dp4[MAXN], dp5[MAXN];
US<int> vis1[MAXN];

void init() {
    FOR(i,1,n+1) {
        US<int> vis, vis2;
        FORX(u,v[i]) v2[i].PB(u);
        FORX(u,v[i+1]) {
            if (!vis2.count(u.F)) {
                vis2.insert(u.F);
                v1[i].PB(u.F);
            }
        }
        FORX(u,v[i-1]) {
            if (!vis2.count(u.F)) {
                vis2.insert(u.F);
                v1[i].PB(u.F);
            }
        }
    }
    FOR(i,1,n+1) {
        sort(ALL(v[i]));
        sort(ALL(v1[i]));
        sort(ALL(v2[i]));
    }
    FOR(i,1,n+1) {
        int cur = 0LL;
        FORX(u,v2[i]) {
            p[i].PB({u.F,cur+u.S});
            cur += u.S;
        }
    }
    dp[1].PB({0LL,0LL});
    dp1[1].PB({0LL,0LL});
    dp2[1].PB({0LL,0LL});
    int ma3 = 0LL;
    int vn = v1[1].size();
    int idx = p[2].size()-1;
    FORR(pos,vn-1,-1) {
        int j = v1[1][pos];
        while (idx > 0 && p[2][idx].F > j) idx--;
        ma3 = max(ma3, p[2][idx].S);
        dp3[1].PB({j,ma3});
    }
    reverse(ALL(dp3[1]));
}

long long max_weights(int32_t N, int32_t M, std::vector<int32_t> X, std::vector<int32_t> Y, std::vector<int32_t> W) {
    OPTM;
    n = N; m = M;
    bool flag = 1;
    int total = 0LL;
    FOR(i,0,m) {
        if (X[i]%2 == 1) flag = 0;
        total += W[i];
    }
    if (flag) return total;
    FOR(i,0,m) {
        if (!vis1[i+1].count(Y[i]+1)) {
            vis1[i+1].insert(Y[i]+1);
            v[X[i]+1].PB({Y[i]+1,W[i]});
        }
    }
    FOR(i,0,n+2) {
        v[i].PB({0LL,0LL});
        if (!vis1[i].count(n)) {
            vis1[i].insert(n);
            v[i].PB({n,0LL});
        }
    }
    init();
    FOR(i,2,n+1) {
        int vn = v1[i].size();
        int idx = 0, idx1 = 0, idx2 = 0, idx3 = dp3[i-1].size()-1;
        int pn = p[i].size(), p1n = p[i-1].size(), dp2n = dp2[i-1].size();
        int ma2 = 0LL;
        FOR(pos,0,vn) {
            int j = v1[i][pos];
            while (idx < pn-1 && p[i][idx+1].F <= j) idx++;
            while (idx1 < p1n-1 && p[i-1][idx1+1].F <= j) idx1++;
            while (idx2 < dp2n-1 && dp2[i-1][idx2+1].F <= j) idx2++;
            while (idx3 > 0 && dp3[i-1][idx3-1].F >= j) idx3--;
            int zero = max(dp4[i-1], dp5[i-1]+p[i-1][idx1].S);
            dp[i].PB({j, max(zero, dp2[i-1][idx2].S + p[i-1][idx1].S)});
            dp1[i].PB({j, max(zero, dp3[i-1][idx3].S - p[i][idx].S)});
            ma2 = max(ma2, dp[i][pos].S - p[i][idx].S);
            dp2[i].PB({j,ma2});
            dp4[i] = max(dp4[i], max(dp[i-1][idx2].S, dp1[i-1][idx2].S) + p[i][idx].S);
            dp5[i] = max(dp5[i], max(dp[i-1][idx2].S, dp1[i-1][idx2].S));
        }
        if (i == n) break;
        int ma3 = 0LL;
        idx = p[i+1].size()-1;
        FORR(pos,vn-1,-1) {
            int j = v1[i][pos];
            while (idx > 0 && p[i+1][idx].F > j) idx--;
            ma3 = max(ma3, max(dp[i][pos].S, dp1[i][pos].S) + p[i+1][idx].S);
            dp3[i].PB({j,ma3});
        }
        reverse(ALL(dp3[i]));
    }
    int res = -LLINF;
    FORX(u,dp[n]) res = max(res, u.S);
    FORX(u,dp1[n]) res = max(res, u.S);
    return res;
}