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
const ll LLINF = 1e18+1;
#define int long long

const int MAXN = 1e3+5;
int n;
int g[3][MAXN];
vector<int> v[MAXN], r[MAXN], topo;
set<int> cur;
bool z[MAXN], z1[MAXN];

void dfs(int s) {
    if (z[s]) return;
    z[s] = 1;
    FORX(u,v[s]) dfs(u);
    topo.PB(s);
}

void dfs1(int s) {
    if (z1[s]) return;
    z1[s] = 1;
    cur.insert(s);
    FORX(u,r[s]) dfs1(u);
}

bool solve() {
    cin >> n;
    FOR(i,0,n*2+1) {
        v[i].clear();
        r[i].clear();
        z[i] = z1[i] = 0;
    }
    FOR(i,0,3) FOR(j,0,n) cin >> g[i][j];
    FOR(j,0,n) {
        FOR(i,0,3) {
            int c = g[i][j] < 0 ? 0 : n;
            FOR(k,0,3) {
                if (i == k) continue;
                int d = g[k][j] > 0 ? 0 : n;
                v[abs(g[i][j])+c].PB(abs(g[k][j])+d);
                r[abs(g[k][j])+d].PB(abs(g[i][j])+c);
            }
        }
    }
    FOR(i,1,n*2+1) dfs(i);
    reverse(ALL(topo));
    FOR(i,0,n*2) {
        if (z1[topo[i]]) continue;
        cur.clear();
        dfs1(topo[i]);
        FORX(u,cur) if (u <= n && cur.count(u+n)) return 0;
    }
    return 1;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << ln;
}