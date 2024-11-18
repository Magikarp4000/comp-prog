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

const int MAXN = 1e5+1;
int n,m;
vector<pair<ll,PII>> e;
vector<int> v[MAXN];
bool z[MAXN];
int p[MAXN], sz[MAXN];
ll res = 0;

int finds(int a) {
    if (p[a] != a) p[a] = finds(p[a]);
    return p[a];
}

void unite(int a, int b, ll w) {
    a = finds(a);
    b = finds(b);
    if (a != b) {
        res += w;
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(int s) {
    if (z[s]) return;
    z[s] = 1;
    FORX(u,v[s]) dfs(u);
}

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,m) {
        int a,b; ll w;
        cin >> a >> b >> w;
        v[a].PB(b);
        v[b].PB(a);
        e.PB({w,{a,b}});
    }
    sort(ALL(e));
    int cnt = 0;
    FOR(i,1,n+1) {
        if (!z[i]) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt != 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    FOR(i,1,n+1) {
        p[i] = i;
        sz[i] = 1;
    }
    FOR(i,0,m) unite(e[i].S.F, e[i].S.S, e[i].F);
    cout << res;
}