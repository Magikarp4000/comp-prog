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

const int MAXN = 5e5+5;
int n;
vector<int> v[MAXN];
int d[MAXN], mx[MAXN], dp[MAXN], dp1[MAXN];

void reset() {
    FOR(i,0,n+2) {
        d[i] = mx[i] = dp[i] = dp1[i] = 0;
        v[i].clear();
    }
}

void dfs(int s, int pa) {
    mx[s] = d[s];
    FORX(u,v[s]) {
        if (u == pa) continue;
        d[u] = d[s]+1;
        dfs(u,s);
        mx[s] = max(mx[s], mx[u]);
    }
    // cout << "s mx[s] " << s << " " << mx[s] << ln;
    dp[mx[s]+1]++;
    if (d[s] > 0) dp1[d[s]-1]++;
}

int solve() {
    cin >> n;
    reset();
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b); v[b].PB(a);
    }
    dfs(1,-1);
    FOR(i,1,n+1) dp[i] += dp[i-1];
    FORR(i,n,-1) dp1[i] += dp1[i+1];
    int res = INF;
    FOR(i,0,n+1) res = min(res, dp[i]+dp1[i]);
    // FOR(i,0,n+1) cout << dp[i] << " ";
    // cout << ln;
    // FOR(i,0,n+1) cout << dp1[i] << " ";
    // cout << ln;
    return res;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << solve() << ln;
}