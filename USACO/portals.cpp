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

const int MAXN = 2e5+1;
int n;
vector<pair<int,PLL>> edges;
int perm[4];
int p[MAXN], sz[MAXN];

void addedge(int a, int b, int w) {
    edges.PB({w,{a,b}});
}

int finds(int a) {
    if (p[a] != a) p[a] = finds(p[a]);
    return p[a];
}

int unite(int a, int b, int w) {
    a = finds(a);
    b = finds(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
        return w;
    }
    return 0;
}

void main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) {
        int c; cin >> c;
        FOR(j,0,4) cin >> perm[j];
        addedge(perm[0],perm[1],0);
        addedge(perm[2],perm[3],0);
        addedge(perm[0],perm[2],c);
        addedge(perm[1],perm[3],c);
    }
    sort(ALL(edges));
    FOR(i,1,2*n+1) {
        p[i] = i;
        sz[i] = 1;
    }
    int res = 0;
    FORX(u,edges) {
        res += unite(u.S.F, u.S.S, u.F);
    }
    cout << res;
}