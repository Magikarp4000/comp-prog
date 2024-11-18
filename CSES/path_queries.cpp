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
int n,q;
vector<int> v[MAXN];
int a[MAXN], mp[MAXN], sz[MAXN];
ll ft[MAXN*2];
vector<int> tour;

void dfs(int s, int pa) {
    sz[s] = 1;
    tour.PB(s);
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        sz[s] += sz[u];
    }
}

void update(int k, int x) {
    while (k <= n) {
        ft[k] += x;
        k += k&(-k);
    }
}

int query(int k) {
    int cur = 0;
    while (k > 0) {
        cur += ft[k];
        k -= k&(-k);
    }
    return cur;
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,1,n+1) cin >> a[i];
    FOR(i,0,n-1) {
        int x,y; cin >> x >> y;
        v[x].PB(y);
        v[y].PB(x);
    }
    dfs(1,-1);
    FOR(i,0,n) mp[tour[i]] = i+1;
    FOR(i,1,n+1) {
        update(i,a[tour[i-1]]);
        update(i+sz[tour[i-1]],-a[tour[i-1]]);
    }
    FOR(_,0,q) {
        int t,s,x;
        cin >> t;
        if (t == 1) {
            cin >> s >> x;
            int diff = x-a[s];
            update(mp[s],diff);
            update(mp[s]+sz[s],-diff);
            a[s] = x;
        }
        else {
            cin >> s;
            cout << query(mp[s]) << ln;
        }
    }
}