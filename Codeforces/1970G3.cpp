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
const ll LLINF = 5e18+1;
#define int long long

const int MAXN = 1e5+5;
int n,m,c;
vector<int> v[MAXN];
int res, cnt, t[MAXN], low[MAXN], sz[MAXN], dp[2][MAXN];
bool z[MAXN], z1[MAXN];
vector<PII> compsz;
bitset<MAXN> bt[2];

void bruh(int x, int y, int last) {
    FOR(i,0,n+1) {
        if (!dp[last][i]) continue;
        res = min(res, min((x+i)*(x+i)+(n-x-i)*(n-x-i), (y+i)*(y+i)+(n-y-i)*(n-y-i)));
    }
}

void dfs(int s) {
    sz[s] = z[s] = 1;
    FORX(u,v[s]) {
        if (z[u]) continue;
        dfs(u);
        sz[s] += sz[u];
    }
}

void dfs1(int s, int pa, int csz, int last) {
    t[s] = low[s] = cnt++;
    z1[s] = 1;
    FORX(u,v[s]) {
        if (u == pa) continue;
        if (z1[u]) {
            low[s] = min(low[s], t[u]);
            continue;
        }
        dfs1(u,s,csz,last);
        low[s] = min(low[s], low[u]);
        if (low[u] > t[s]) bruh(sz[u],csz-sz[u],last); // is bridge
    }
}

void reset() {
    FOR(i,0,n+1) {
        z[i] = z1[i] = t[i] = low[i] = sz[i] = 0;
        v[i].clear();
    }
    compsz.clear();
    cnt = 0;
    res = LLINF;
}

void solve() {
    cin >> n >> m >> c;
    reset();
    FOR(i,0,m) {
        int a,b; cin >> a >> b;
        v[a].PB(b), v[b].PB(a);
    }
    FOR(i,1,n+1) {
        if (z[i]) continue;
        dfs(i);
        compsz.PB({sz[i],i});
    }
    int cn = compsz.size(), cur = 1, pre = 0;
    bt[pre].set(0);
    FORX(u,compsz) {
        bt[cur] = bt[pre] | (bt[pre]>>u.F);
        swap(cur,pre);
    }
    FORX(u,compsz) {
        bitset<MAXN> bt1 = bt[pre]<<u.F;
        dfs1(u.S,-1,u.F,pre);
    }
    FORX(u,compsz) {
        dfs1(u.S,-1,sz[u.S],pre);
        if (compsz.size() > 1) bruh(u.F,0,pre);
    }
    cout << (res == LLINF ? -1 : res+c*(int32_t(compsz.size())-1)) << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}