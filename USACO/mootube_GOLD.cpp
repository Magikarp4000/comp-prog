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
int n,q;
pair<int,PII> a[MAXN];
pair<int,PII> qrs[MAXN];
int p[MAXN], sz[MAXN], res[MAXN];

int finds(int x) {
    if (p[x] != x) p[x] = finds(p[x]);
    return p[x];
}

void unify(int x, int y) {
    x = finds(x);
    y = finds(y);
    if (x != y) {
        if (sz[y] > sz[x]) swap(x,y);
        p[y] = x;
        sz[x] += sz[y];
    }
}

signed main() {
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    OPTM;
    cin >> n >> q;
    FOR(i,1,n+1) {
        p[i] = i;
        sz[i] = 1;
    }
    FOR(i,0,n-1) {
        int x,y,r; cin >> x >> y >> r;
        a[i] = {r,{x,y}};
    }
    sort(a,a+n-1,greater<pair<int,PII>>());
    FOR(i,0,q) {
        int r,x; cin >> r >> x;
        qrs[i] = {r,{x,i}};
    }
    sort(qrs,qrs+q,greater<pair<int,PII>>());
    int j = 0;
    FOR(i,0,q) {
        while (j < n-1 && a[j].F >= qrs[i].F) {
            unify(a[j].S.F, a[j].S.S);
            j++;
        }
        res[qrs[i].S.S] = sz[finds(qrs[i].S.F)]-1;
    }
    FOR(i,0,q) cout << res[i] << ln;
}