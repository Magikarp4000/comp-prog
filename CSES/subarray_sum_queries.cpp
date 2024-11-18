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

struct Node {
    int x,sum,pre,suf;
};

const int MAXN = 2e5+1;
int n,q;
Node st[MAXN*4+10];

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        st[s].pre = st[s].suf = st[s].x = max(0LL,val);
        st[s].sum = val;
    }
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s].pre = max(st[s*2].pre, st[s*2].sum+st[s*2+1].pre);
        st[s].suf = max(st[s*2+1].suf, st[s*2+1].sum+st[s*2].suf);
        st[s].x = max(max(st[s*2].x, st[s*2+1].x), st[s*2].suf+st[s*2+1].pre);
        st[s].sum = st[s*2].sum+st[s*2+1].sum;
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s].x;
    else {
        int tm = (tl+tr)/2;
        int cur = 0LL;
        if (l <= tm) cur = max(cur, query(s*2,tl,tm,l,r));
        if (r > tm) cur = max(cur, query(s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

void update_(int idx, int val) {update(1,0,n-1,idx,val);}
int query_(int l, int r) {return query(1,0,n-1,l,r);}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) {
        int x; cin >> x;
        update_(i,x);
    }
    FOR(_,0,q) {
        int k,x; cin >> k >> x;
        k--;
        update_(k,x);
        cout << query_(0,n-1) << ln;
    }
}