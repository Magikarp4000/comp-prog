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

const int MAXN = 1e2+5, MAXM = 1e3+5;
int n,m;
int s[MAXN], l[MAXN], dp[MAXM][MAXN];

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) cin >> s[i];
    FOR(i,0,n) cin >> l[i];
    dp[0][0] = 1LL;
    FOR(i,1,m+1) {
        FOR(j,0,n) {
            FOR(k,0,n) dp[i][j] = (dp[i][j] + dp[i-1][k]*(s[j]*s[k]+s[j]*l[k]+l[j]*s[k]))%INF;
        }
    }
    cout << ln;
    int res = 0;
    FOR(i,0,n) res = (res+dp[m][i])%INF;
    FOR(i,0,m+1) {
        FOR(j,0,n) cout << dp[i][j] << " ";
        cout << ln;
    }
    cout << res << ln;
}