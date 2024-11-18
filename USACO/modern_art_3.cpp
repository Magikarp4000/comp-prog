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

const int MAXN = 3e2+1;
int n;
int a[MAXN], dp[MAXN][MAXN];

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) FOR(j,0,n) dp[i][j] = INF;
    FOR(i,0,n) dp[i][i] = 1;
    FOR(l,1,n) {
        FOR(i,0,n-l) {
            int j = i+l;
            FOR(k,i,j) {
                if (a[i] == a[j]) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]-1);
                else dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1];
}