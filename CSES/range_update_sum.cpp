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
const ll LLINF = 0;
#define int long long

struct Node {
    ll x,setas,incr;
    bool valid;
};

const int MAXN = 2e5+1;
int n,q;
Node st[MAXN*4+10];
ll w[MAXN];

void pushdown(int s, int tl, int tr) {
    int tm = (tl+tr)/2;
    if (st[s].valid) {
        st[s*2].setas = st[s].setas;
        st[s*2].valid = 1;
        st[s*2].incr = st[s].incr;
        st[s*2].x = (st[s].setas+st[s].incr)*(tm-tl+1);
        st[s*2+1].setas = st[s].setas;
        st[s*2+1].valid = 1;
        st[s*2+1].incr = st[s].incr;
        st[s*2+1].x = (st[s].setas+st[s].incr)*(tr-tm);
        st[s].valid = 0;
        st[s].incr = 0;
    }
    else {
        st[s*2].incr += st[s].incr;
        st[s*2].x += (st[s].incr)*(tm-tl+1);
        st[s*2+1].incr += st[s].incr;
        st[s*2+1].x += (st[s].incr)*(tr-tm);
        st[s].incr = 0;
    }
}

void set_all(int s, int tl, int tr, int l, int r, ll val) {
    if (l == tl && r == tr) {
        st[s].setas = val;
        st[s].valid = 1;
        st[s].incr = 0;
        st[s].x = val*(tr-tl+1);
    }
    else {
        pushdown(s,tl,tr);
        int tm = (tl+tr)/2;
        if (l <= tm) set_all(s*2, tl, tm, l, min(tm,r), val);
        if (r > tm) set_all(s*2+1, tm+1, tr, max(l,tm+1), r, val);
        st[s].x = st[s*2].x + st[s*2+1].x;
    }
}

void add(int s, int tl, int tr, int l, int r, ll val) {
    if (l == tl && r == tr) {
        st[s].incr += val;
        st[s].x += val*(tr-tl+1);
    }
    else {
        pushdown(s,tl,tr);
        int tm = (tl+tr)/2;
        if (l <= tm) add(s*2, tl, tm, l, min(tm,r), val);
        if (r > tm) add(s*2+1, tm+1, tr, max(l,tm+1), r, val);
        st[s].x = st[s*2].x + st[s*2+1].x;
    }
}

ll query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) {
        return st[s].x;
    }
    else {
        pushdown(s,tl,tr);
        int tm = (tl+tr)/2;
        ll res = 0;
        if (l <= tm) res += query(s*2, tl, tm, l, r);
        if (r > tm) res += query(s*2+1, tm+1, tr, l, r);
        return res;
    }
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) cin >> w[i];
    FOR(i,0,n) {
        set_all(1,0,n-1,i,i,w[i]);
    }
    FOR(i,0,q) {
        int t,a,b;
        cin >> t >> a >> b;
        a--; b--;
        if (t == 1) {
            ll x; cin >> x;
            add(1,0,n-1,a,b,x);
        }
        else if (t == 2) {
            ll x; cin >> x;
            set_all(1,0,n-1,a,b,x);
        }
        else if (t == 3) {
            cout << query(1,0,n-1,a,b) << ln;
        }
    }
}