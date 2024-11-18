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
int n,q;
ll a[MAXN];
vector<int> v[MAXN];
int sta[MAXN], en[MAXN];
ll st[MAXN*4];
int t = 1;

void dfs(int s, int pa) {
    sta[s] = t;
    t++;
    FORX(u,v[s]) {
        if (u != pa) dfs(u,s);
    }
    en[s] = t-1;
}

void update(int s, int tl, int tr, int k, ll x) {
    if (tl == tr) st[s] = x;
    else {
        int tm = (tl+tr)/2;
        if (k <= tm) update(s*2,tl,tm,k,x);
        else update(s*2+1,tm+1,tr,k,x);
        st[s] = st[s*2]+st[s*2+1];
    }
}

ll query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    else {
        ll sum = 0;
        int tm = (tl+tr)/2;
        if (l <= tm) sum += query(s*2,tl,tm,l,r);
        if (r >= tm+1) sum += query(s*2+1,tm+1,tr,l,r);
        return sum;
    }
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
    FOR(i,1,n+1) update(1,1,n,sta[i],a[i]);
    FOR(i,0,q) {
        int t; cin >> t;
        if (t == 1) {
            int k; ll x;
            cin >> k >> x;
            update(1,1,n,sta[k],x);
        }
        else {
            int k; cin >> k;
            cout << query(1,1,n,sta[k],en[k]) << ln;
        }
    }
}