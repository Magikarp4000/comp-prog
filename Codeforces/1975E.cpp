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

const int MAXN = 2e5+5, LOG = 18;
int n,q;
int c[MAXN], par[MAXN], d[MAXN], jp[MAXN][LOG], cnt[MAXN];
vector<int> v[MAXN];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        par[u] = s;
        d[u] = d[s]+1;
        cnt[s] += c[u];
        dfs(u,s);
    }
}

int lca(int a, int b) {
    if (d[a] > d[b]) swap(a,b);
    FORR(j,LOG-1,-1) {
        if (d[jp[b][j]] >= d[a]) b = jp[b][j];
    }
    if (a == b) return a;
    FORR(j,LOG-1,-1) {
        if (jp[a][j] != jp[b][j]) {
            a = jp[a][j];
            b = jp[b][j];
        }
    }
    return par[a];
}

void solve() {
    cin >> n >> q;
    FOR(i,0,n+1) {
        FOR(j,0,LOG) jp[i][j] = 0;
        c[i] = d[i] = par[i] = cnt[i] = 0;
        v[i].clear();
    }
    FOR(i,1,n+1) cin >> c[i];
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b), v[b].PB(a);
    }
    dfs(1,-1);
    FOR(i,1,n+1) jp[i][0] = par[i];
    FOR(j,1,LOG) FOR(i,1,n+1) jp[i][j] = jp[jp[i][j-1]][j-1];
    int num = 0;
    US<int> ends;
    FOR(i,1,n+1) {
        if (c[i] && cnt[i] == 0) ends.insert(i);
        if (c[i] && !c[par[i]]) num++;
    }
    FOR(i,0,q) {
        int x; cin >> x;
        c[x] ^= 1;
        if (c[x]) {
            num -= cnt[x];
            if (!c[par[x]]) num++;
            cnt[par[x]]++;
            if (cnt[x] == 0) ends.insert(x);
            if (ends.count(par[x])) ends.erase(par[x]);
        }
        else {
            num += cnt[x];
            if (!c[par[x]]) num--;
            cnt[par[x]]--;
            if (ends.count(x)) ends.erase(x);
            if (c[par[x]] && cnt[par[x]] == 0) ends.insert(par[x]);
        }
        if (num != 1) cout << "NO";
        else if (ends.size() > 2) cout << "NO";
        else if (ends.size() == 2 && c[par[lca(*ends.begin(),*(++ends.begin()))]]) cout << "NO";
        else cout << "YES";
        cout << ln;
    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}