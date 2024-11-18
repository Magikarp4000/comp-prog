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

const int MAXN = 1e5+1, MAXM = 27;
int n,m,K;
string s;
int c[MAXM][MAXM], d[MAXM][MAXM], p[MAXN][MAXM];
int dp[MAXN][MAXM], dp1[MAXN];

signed main() {
    freopen("cowmbat.in","r",stdin);
    freopen("cowmbat.out","w",stdout);
    OPTM;
    cin >> n >> m >> K >> s;
    FOR(i,0,m) FOR(j,0,m) cin >> d[i][j];
    FOR(k,0,m) {
        FOR(i,0,m) {
            FOR(j,0,m) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    FOR(i,1,n+1) {
        FOR(j,0,m) p[i][j] = p[i-1][j]+d[s[i-1]-'a'][j];
    }
    FOR(i,0,n+1) FOR(j,0,m) dp[i][j] = LLINF;
    FOR(i,1,n+1) dp1[i] = LLINF;
    FOR(i,1,n+1) {
        FOR(j,0,m) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]+d[s[i-1]-'a'][j]);
            if (i >= K) dp[i][j] = min(dp[i][j], p[i][j]-p[i-K][j]+dp1[i-K]);
        }
        FOR(j,0,m) dp1[i] = min(dp1[i], dp[i][j]);
    }
    cout << dp1[n];
}