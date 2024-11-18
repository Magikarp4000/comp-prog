#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+7)
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

const int MAXN = 10, MAXM = 1e3+1;
int n,m;
int dp[1<<MAXN][2];

signed main() {
    OPTM;
    cin >> n >> m;
    dp[(1<<n)-1][0] = 1;
    FOR(j,0,m) {
        FOR(i,0,n) {
            FOR(s,0,1<<n) {
                if (s&(1<<i)) {
                    dp[s][1] = (dp[s][1]+dp[s^(1<<i)][0])%INF;
                    if (i > 0 && s&(1<<(i-1))) dp[s][1] = (dp[s][1]+dp[s^(1<<(i-1))][0])%INF;
                }
                else dp[s][1] = (dp[s][1]+dp[s^(1<<i)][0])%INF;
            }
            FOR(s,0,1<<n) {
                dp[s][0] = dp[s][1];
                dp[s][1] = 0;
            }
        }
        
    }
    cout << dp[(1<<n)-1][0];
}