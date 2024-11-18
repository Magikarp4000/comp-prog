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
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 1e3+1;
int n;
char g[MAXN][MAXN];
ll dp[2][MAXN][MAXN];

signed main() {
    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) FOR(j,0,n) cin >> g[i][j];
    FOR(i,0,n) dp[0][i][n-i-1] = 1;
    FOR(l,1,n) {
        FOR(i,l,n) {
            int y = i, x = n-i-1+l;
            FOR(j,0,n) {
                int px = j, py = n-l-j;
                if (px < 0 || py < 0) continue;
                if (px > 0 && g[py][px-1] == g[y][x]) {
                    dp[1][y][px-1] = (dp[1][y][px-1]+dp[0][y][px])%INF;
                    dp[1][y][px-1] = (dp[1][y][px-1]+dp[0][y-1][px])%INF;
                }
                if (py > 0 && g[py-1][px] == g[y][x]) {
                    dp[1][y][px] = (dp[1][y][px]+dp[0][y][px])%INF;
                    dp[1][y][px] = (dp[1][y][px]+dp[0][y-1][px])%INF;
                }
            }
        }
        FOR(i,0,n) FOR(j,0,n) dp[0][i][j] = dp[1][i][j];
        FOR(i,0,n) FOR(j,0,n) dp[1][i][j] = 0ll;
    }
    cout << dp[0][n-1][0];
}