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
const ll LLINF = 4e18+1;
#define int long long

const int MAXN = 1e5+5;
int n,m,c;
int res,dp[MAXN];
vector<int> v[MAXN];

void dfs(int s, int pa) {
    dp[s] = 1;
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        dp[s] += dp[u];
    }
    res = min(res, dp[s]*dp[s] + (n-dp[s])*(n-dp[s]));
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> c;
        FOR(i,1,n+1) v[i].clear();
        res = LLINF;
        FOR(i,0,m) {
            int a,b; cin >> a >> b;
            v[a].PB(b), v[b].PB(a);
        }
        if (n == 1) {
            cout << -1 << ln;
            continue;
        }
        dfs(1,-1);
        cout << res << ln;
    }
}