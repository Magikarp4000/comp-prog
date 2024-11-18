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

const int MAXN = 1e2+1, MAXH = 1e3+1;
int n;
int h[MAXN], dp[MAXN][MAXH], p[MAXH], b[MAXN];

int solve(int shift) {
    FOR(i,1,n+1) FOR(j,0,MAXH) dp[i][j] = 0LL;
    FOR(i,1,n+1) {
        b[i] = h[i]-shift;
        if (b[i] < 0) return 0LL;
    }
    dp[1][0] = 1LL;
    FOR(i,0,MAXH) p[i] = 1LL;
    FOR(i,2,n+1) {
        FOR(j,0,b[i]+1) {
            if (b[i-1]-j >= 0LL) dp[i][j] = p[b[i-1]-j];
        }
        p[0] = dp[i][0];
        FOR(j,1,b[i]+1) {
            p[j] = (p[j-1]+dp[i][j])%INF;
        }
    }
    int ans = 0LL;
    FOR(j,0,b[n]+1) ans = (ans+dp[n][j])%INF;
    return ans;
}

signed main() {
    cin >> n;
    FOR(i,1,n+1) cin >> h[i];
    FOR(j,0,MAXH) dp[0][j] = 1LL;
    FOR(j,1,MAXH) p[j] = p[j-1]+dp[0][j];
    if (n%2 == 0) {
        cout << solve(0LL);
        return 0;
    }
    int res = 0LL;
    FOR(i,0,MAXH) res = (res+solve(i))%INF;
    cout << res;
}