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

const int MAXN = 2e5+1;
int n,m;
vector<int> v[MAXN];
int c[MAXN];
int p[MAXN], sz[MAXN];
bool z[MAXN];

int finds(int s) {
    if (p[s] != s) p[s] = finds(p[s]);
    return p[s];
}

void unite(int a, int b) {
    a = finds(a);
    b = finds(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

signed main() {
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    OPTM;
    cin >> n >> m;
    FOR(i,0,m) {
        int a,b; cin >> a >> b;
        v[a].PB(b);
        v[b].PB(a);
    }
    FOR(i,0,n) cin >> c[i];
    reverse(c,c+n);
    FOR(i,1,n+1) {
        p[i] = i;
        sz[i] = 1;
    }
    vector<string> res;
    res.PB("YES");
    z[c[0]] = 1;
    FOR(i,1,n) {
        int s = c[i];
        z[s] = 1;
        FORX(u,v[s]) if (z[u]) unite(s,u);
        if (sz[finds(s)] != i+1) res.PB("NO");
        else res.PB("YES");
    }
    reverse(ALL(res));
    FORX(u,res) cout << u << ln;
}