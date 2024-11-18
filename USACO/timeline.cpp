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

const int MAXN = 1e5+1;
int n,m,c;
int a[MAXN];
vector<PII> v[MAXN];
bool z[MAXN];
vector<int> t;
int dp[MAXN];

void dfs(int s) {
    if (z[s]) return;
    z[s] = 1;
    FORX(u,v[s]) dfs(u.F);
    t.PB(s);
}

signed main() {
    freopen("timeline.in","r",stdin);
    freopen("timeline.out","w",stdout);
    OPTM;
    cin >> n >> m >> c;
    FOR(i,1,n+1) cin >> a[i];
    FOR(i,0,c) {
        int x,y,w; cin >> x >> y >> w;
        v[x].PB({y,w});
    }
    FOR(i,1,n+1) dfs(i);
    reverse(ALL(t));
    dp[t[0]] = a[t[0]];
    FORX(s,t) {
        dp[s] = max(dp[s], a[s]);
        FORX(u,v[s]) dp[u.F] = max(dp[u.F], dp[s]+u.S);
    }
    FOR(i,1,n+1) cout << dp[i] << ln;
}