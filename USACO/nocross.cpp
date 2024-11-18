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
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 1e3+1;
int n;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

signed main() {
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) cin >> b[i];
    FOR(i,1,n+1) {
        FOR(j,1,n+1) {
            if (abs(a[i-1]-b[j-1]) <= 4) dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i][j-1], dp[i-1][j]));
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][n];
}