#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+9)
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

const int MAXN = 1e3+1, MAXK = 11;
int n,m,K;
int a[MAXN], b[MAXN], dp[MAXK][MAXN][MAXN];

signed main() {
    freopen("team.in","r",stdin);
    freopen("team.out","w",stdout);
    OPTM;
    cin >> n >> m >> K;
    FOR(i,1,n+1) cin >> a[i];
    FOR(i,1,m+1) cin >> b[i];
    FOR(i,0,n+1) FOR(j,0,m+1) dp[0][i][j] = 1LL;
    FOR(k,1,K+1) {
        FOR(i,1,n+1) {
            FOR(j,1,m+1) {
                dp[k][i][j] = ((dp[k][i-1][j]+dp[k][i][j-1])%INF-dp[k][i-1][j-1]+INF)%INF;
                if (a[i] > b[j]) dp[k][i][j] = (dp[k][i][j]+dp[k-1][i-1][j-1])%INF;
            }
        }
    }
    cout << dp[K][n][m];
}