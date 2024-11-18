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

const int MAXN = 102, MAXK = 52;
int n,k;
vector<PII> v[MAXN];
int p[MAXN], val[MAXN], depth[MAXN];
int dp[MAXN][MAXN][MAXK];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        if (u.F == pa) continue;
        depth[u.F] = depth[s]+u.S;
        dfs(u.F,s);
    }
}

void dfs1(int s, int pa) {
    vector<int> adj;
    FORX(u,v[s]) {
        if (u.F == pa) continue;
        dfs1(u.F,s);
        adj.PB(u.F);
    }
    int an = adj.size(), cur = s;
    while (cur != -1) {
        vector<vector<int>> dp1(an+1,vector<int>(k+1,INF));
        dp1[0][0] = 0;
        FOR(i,1,an+1) {
            FOR(j,0,k+1) {
                FOR(l,0,j+1) {
                    dp1[i][j] = min(dp1[i][j], dp1[i-1][j-l]+dp[adj[i-1]][cur][l]);
                }
            }
        }
        if (cur == s) {
            int cur1 = s;
            while (cur1 != -1) {
                FOR(i,1,k+1) dp[s][cur1][i] = dp1[an][s == 0 ? i : i-1];
                cur1 = p[cur1];
            }
        }
        else {
            FOR(i,0,k+1) dp[s][cur][i] = min(dp[s][cur][i], dp1[an][i]+val[s]*(depth[s]-depth[cur]));
        }
        cur = p[cur];
    }
}

signed main() {
    freopen("river.in","r",stdin);
    freopen("river.out","w",stdout);
    OPTM;
    cin >> n >> k;
    FOR(i,1,n+1) {
        int pa,d; cin >> val[i] >> pa >> d;
        p[i] = pa;
        v[pa].PB({i,d});
    }
    p[0] = -1;
    FOR(i,0,n+1) FOR(j,0,n+1) FOR(l,0,k+1) dp[i][j][l] = INF;
    dfs(0,-1);
    dfs1(0,-1);
    cout << dp[0][0][k];
}