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

const int MAXN = 1e5+1;
int n,k;
vector<int> v[MAXN];
int a[MAXN];
int dp[MAXN][3];

void dfs(int s, int pa) {
    dp[s][0] = dp[s][1] = dp[s][2] = 1;
    vector<bool> z(3,0);
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        dp[s][0] = (dp[s][0]*(dp[u][1]+dp[u][2])%INF)%INF;
        dp[s][1] = (dp[s][1]*(dp[u][0]+dp[u][2])%INF)%INF;
        dp[s][2] = (dp[s][2]*(dp[u][0]+dp[u][1])%INF)%INF;
        if (a[u] != 0) z[a[u]-1] = 1;
    }
    if (a[s] == 1) dp[s][1] = dp[s][2] = 0;
    else if (a[s] == 2) dp[s][0] = dp[s][2] = 0;
    else if (a[s] == 3) dp[s][0] = dp[s][1] = 0;
    FOR(i,0,3) if (z[i]) dp[s][i] = 0;
}

signed main() {
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);
    OPTM;
    cin >> n >> k;
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b);
        v[b].PB(a);
    }
    FOR(i,0,k) {
        int idx,c; cin >> idx >> c;
        a[idx] = c;
    }
    dfs(1,-1);
    cout << ((dp[1][0]+dp[1][1])%INF+dp[1][2])%INF;
}