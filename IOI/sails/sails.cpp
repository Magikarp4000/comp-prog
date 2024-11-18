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

struct Node {
    int x,lz;
};

const int MAXN = 1e5+5;
int n;
vector<PII> v;
Node st[MAXN*4+10];

void pushdown(int s) {
    st[s*2].x += st[s].lz;
    st[s*2].lz += st[s].lz;
    st[s*2+1].x += st[s].lz;
    st[s*2+1].lz += st[s].lz;
    st[s].lz = 0LL;
}

void update(int s, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l <= tl && r >= tr) {
        st[s].x += val;
        st[s].lz += val;
    }
    else {
        pushdown(s);
        int tm = (tl+tr)/2;
        if (l <= tm) update(s*2,tl,tm,l,r,val);
        if (r > tm) update(s*2+1,tm+1,tr,l,r,val);
        st[s].x = st[s*2].x+st[s*2+1].x;
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s].x;
    pushdown(s);
    int tm = (tl+tr)/2;
    int cur = 0LL;
    if (l <= tm) cur += query(s*2,tl,tm,l,r);
    if (r > tm) cur += query(s*2+1,tm+1,tr,l,r);
    return cur;
}

int query(int l, int r) {return query(1,0,MAXN-1,l,r);}
void update(int l, int r, int val) {update(1,0,MAXN-1,l,r,val);}

signed main() {
    freopen("sails.in","r",stdin);
    freopen("sails.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) {
        int h,k; cin >> h >> k;
        v.PB({h,k});
    }
    sort(ALL(v));
    FOR(i,0,n) {
        int h = v[i].F-1, k = v[i].S;
        int val = query(h-k+1,h-k+1);
        int l = 0, r = h;
        while (l < r) {
            int mid = (l+r)/2;
            if (query(mid,mid) <= val) r = mid;
            else l = mid+1;
        }
        int sta = query(l,l) == val ? l : l+1;
        l = 0; r = h;
        while (l < r) {
            int mid = (l+r)/2;
            if (query(mid,mid) < val) r = mid;
            else l = mid+1;
        }
        int en = query(l,l) == val ? l : l-1;
        int rem = k-(h-en);
        update(en+1,h,1LL);
        update(sta,sta+rem-1,1LL);
    }
    int res = 0LL;
    FOR(i,0,MAXN-1) {
        int val = query(i,i);
        res += (val*(val-1LL))/2LL;
    }
    cout << res;
}