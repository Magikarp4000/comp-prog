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
const ll LLINF = 2e18+1;

const int MAXN = 2e6+5, MAXM = 5e3+5;
int n,m;
int p[MAXM], dp[2][MAXM];

signed main() {
    OPTM;
    cin >> n >> m;
    int cnt = 0, cur = 0;
    FOR(i,0,n) {
        int x; cin >> x;
        if (x == 0) {
            FOR(j,1,cnt+1) p[j] += p[j-1];
            FOR(j,0,cnt+2) dp[cur^1][j] = max(dp[cur][j-1]+p[j-1], dp[cur][j]+p[j]);
            FOR(j,0,cnt+1) p[j] = 0;
            cur ^= 1;
            cnt++;
        }
        else if (x > 0) {
            if (x <= cnt) {
                p[x]++;
            }
        }
        else {
            x = -x;
            if (x <= cnt) {
                p[0]++;
                p[cnt-x+1]--;
            }
        }
    }
    FOR(j,1,cnt+1) p[j] += p[j-1];
    FOR(j,0,cnt+1) dp[cur][j] += p[j];
    int res = 0;
    FOR(j,0,cnt+1) res = max(res, dp[cur][j]);
    cout << res;
}