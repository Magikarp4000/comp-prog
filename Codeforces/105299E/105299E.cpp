#include <bits/stdc++.h>
using namespace std;
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,s,n) for (int i = s; i > n; i--)
#define F first
#define S second
#define ln '\n'
#define INF int(1e9+7)
#define INF1 998244353
#define PII pair<int,int>
#define OPTM ios_base::sync_with_stdio(0), cin.tie(0);
#define UM unordered_map

const int MAXN = 1e4+5;
int n,k;
int a[MAXN];
UM<int, UM<int,int>> dp[MAXN];

signed main() {
    OPTM;
    cin >> n >> k;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) {
        int cur = a[i];
        FORR(j,i,0) {
            cur &= a[j];
            for (auto u: dp[j-1][cur]) dp[i][cur][u.F+1] = (dp[i][cur][u.F+1] + u.S) % INF1;
        }
        cur &= a[0];
        dp[i][cur][1] = 1;
    }
    int res = 0;
    for (auto u: dp[n-1]) res = (res + u.S[k]) % INF1;
    // FOR(i,0,n) {
    //     int cur = 0;
    //     for (auto u: dp[i]) if (u.F == 4) cur += u.S;
    //     cout << cur << " ";
    // }
    cout << res;
}