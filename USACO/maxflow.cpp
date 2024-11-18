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
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 5e4+5, LOG = 17;
int n,k;
vector<int> v[MAXN];
int p[MAXN], jp[MAXN][LOG], d[MAXN], dp[MAXN];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        p[u] = s;
        d[u] = d[s]+1;
        dfs(u,s);
    }
}

int lca(int a, int b) {
    if (d[a] < d[b]) swap(a,b);
    FORR(j,LOG-1,-1) {
        if (d[jp[a][j]] >= d[b]) a = jp[a][j];
    }
    if (a == b) return a;
    FORR(j,LOG-1,-1) {
        if (jp[a][j] != jp[b][j]) a = jp[a][j], b = jp[b][j];
    }
    return p[a];
}

void dfs1(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs1(u,s);
        dp[s] += dp[u];
    }
}

signed main() {
    freopen("maxflow.in","r",stdin);
    freopen("maxflow.out","w",stdout);
    OPTM;
    cin >> n >> k;
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b), v[b].PB(a);
    }
    dfs(1,-1);
    FOR(i,1,n+1) jp[i][0] = p[i];
    FOR(j,1,LOG) {
        FOR(i,1,n+1) jp[i][j] = jp[jp[i][j-1]][j-1];
    }
    FOR(i,0,k) {
        int a,b; cin >> a >> b;
        int anc = lca(a,b);
        dp[a]++, dp[b]++;
        dp[anc]--;
        if (p[anc] != 0) dp[p[anc]]--;
    }
    dfs1(1,-1);
    cout << (*max_element(dp+1,dp+n+1));
}