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

const int MAXN = 1e2+1;
int n;
int a[MAXN], dp[MAXN][MAXN], p[MAXN][MAXN];

signed main() {
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,1,n+1) {
        FOR(j,i,n+1) {
            p[i][j] = p[i][j-1];
            if (a[j-1] != j-i) p[i][j]++;
        }
    }
    FOR(i,0,n) {
        FOR(j,0,n) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    FOR(i,1,n) {
        FOR(j,0,n) {
            FOR(k,0,j) {
                dp[i][j] = min(dp[i][j], dp[i-1][k]+p[k+1][j]);
            }
        }
    }
    FOR(i,0,n) {
        int res = INF;
        FOR(j,i,n) res = min(res, dp[i][j]+p[j+1][n]);
        cout << res << ln;
    }
}