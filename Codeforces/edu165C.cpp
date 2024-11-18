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
#define FORX(u,arr) for (auto u : arr)
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

const int MAXN = 3e5+5;
int n,K;
int a[MAXN], p[MAXN], dp[MAXN][15];

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        cin >> n >> K;
        FOR(i,1,n+1) cin >> a[i];
        FOR(i,0,n+1) FOR(j,0,K+1) dp[i][j] = 0;
        FOR(i,1,n+1) p[i] = p[i-1]+a[i];
        FOR(i,1,n+1) {
            FOR(k,1,K+1) dp[i][k] = dp[i-1][k];
            int cur = LLINF;
            FOR(j,1,min(i+1,K+2)) {
                cur = min(cur, a[i-j+1]);
                FOR(k,1,K+1) {
                    if (k-j+1 >= 0) dp[i][k] = max(dp[i][k], dp[i-j][k-j+1]+(p[i]-p[i-j])-j*cur);
                }
            }
        }
        int res = 0;
        FOR(i,0,K+1) res = max(res, dp[n][i]);
        cout << p[n]-res << ln;
    }
}