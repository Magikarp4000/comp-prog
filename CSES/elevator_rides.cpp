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

const int MAXN = 21, MAXS = (1<<20)+1;
int n,x;
int w[MAXN];
int dp[MAXS], dp1[MAXS];

signed main() {
    OPTM;
    cin >> n >> x;
    FOR(i,0,n) cin >> w[i];
    FOR(s,1,(1<<n)) dp[s] = dp1[s] = LLINF;
    dp[0] = 1;
    FOR(s,1,(1<<n)) {
        FOR(i,0,n) {
            if (s&(1<<i)) {
                int u = s^(1<<i);
                if (dp1[u]+w[i] <= x) {
                    if (dp[u] < dp[s]) {
                        dp[s] = dp[u];
                        dp1[s] = dp1[u]+w[i];
                    }
                    else if (dp[u] == dp[s]) dp1[s] = min(dp1[s], dp1[u]+w[i]);
                }
                else {
                    if (dp[u]+1 <= dp[s]) {
                        dp[s] = dp[u]+1;
                        dp1[s] = min(dp1[u], w[i]);
                    }
                    else if (dp[u]+1 == dp[s]) dp1[s] = min(dp1[s], min(dp1[u], w[i]));
                }
            }
        }
    }
    cout << dp[(1<<n)-1];
}