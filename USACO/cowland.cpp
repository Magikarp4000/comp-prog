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
#define int long long

const int MAXN = 1e5+1, LOG = 18;
int n,q;
vector<int> v[MAXN];
int e[MAXN], sz[MAXN], p[MAXN], d[MAXN];
vector<int> tour;
int ft[MAXN], mp[MAXN], anc[MAXN][LOG];

void dfs(int s, int pa) {
    tour.PB(s);
    sz[s] = 1;
    FORX(u,v[s]) {
        if (u == pa) continue;
        d[u] = d[s]+1;
        dfs(u,s);
        p[u] = s;
        sz[s] += sz[u];
    }
}

void update(int k, int x) {
    k++;
    while (k <= n) {
        ft[k] ^= x;
        k += k&(-k);
    }
}

int query(int k) {
    k++;
    int cur = 0;
    while (k > 0) {
        cur ^= ft[k];
        k -= k&(-k);
    }
    return cur;
}

int lca(int a, int b) {
    if (d[a] < d[b]) swap(a,b);
    FORR(j,LOG-1,-1) {
        if (d[a]-(1<<j) >= d[b]) a = anc[a][j];
    }
    if (a == b) return a;
    FORR(j,LOG-1,-1) {
        if (anc[a][j] != anc[b][j]) {
            a = anc[a][j];
            b = anc[b][j];
        }
    }
    return p[a];
}

signed main() {
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    OPTM;
    cin >> n >> q;
    FOR(i,1,n+1) cin >> e[i];
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(1,-1);
    FOR(i,0,n) mp[tour[i]] = i;
    FOR(i,1,n+1) anc[i][0] = p[i];
    FOR(j,1,LOG) {
        FOR(i,1,n+1) {
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    FOR(i,1,n+1) {
        update(mp[i],e[i]);
        update(mp[i]+sz[i],e[i]);
    }
    FOR(i,0,q) {
        int t; cin >> t;
        if (t == 1) {
            int k,x; cin >> k >> x;
            int diff = x^e[k];
            update(mp[k],diff);
            update(mp[k]+sz[k],diff);
            e[k] = x;
        }
        else {
            int a,b; cin >> a >> b;
            int res = query(mp[a])^query(mp[b])^e[lca(a,b)];
            cout << res << ln;
        }
    }
}