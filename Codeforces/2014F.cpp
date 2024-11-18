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
#define int long long

const int MAXN = 2e5+5;
int n,c;
int w[MAXN], dp[MAXN][2];
vector<int> v[MAXN];

void reset() {
    FOR(i,0,n) {
        w[i] = dp[i][0] = dp[i][1] = 0;
        v[i].clear();
    }
}

void dfs(int s, int pa) {
    dp[s][1] = w[s];
    for (auto u: v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        dp[s][0] += max(dp[u][0], dp[u][1]);
        dp[s][1] += max(dp[u][0], dp[u][1]-2LL*c);
    }
}

int solve() {
    cin >> n >> c;
    reset();
    FOR(i,0,n) cin >> w[i];
    FOR(_,0,n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        v[a].PB(b); v[b].PB(a);
    }
    dfs(0,-1);
    return max(dp[0][0], dp[0][1]);
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << solve() << ln;
}