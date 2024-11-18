#include "meetings.h"
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

const int MAXN = 5e3+5, MAXN1 = 1e5+5;
int n,q;
int h[MAXN1], le[MAXN][MAXN], ri[MAXN][MAXN];
vector<PII> qu;
vector<int> resv;
int st[MAXN1*4+10];

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st[s] = val;
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = max(st[s*2], st[s*2+1]);
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l > r) return 0LL;
    if (l <= tl && r >= tr) return st[s];
    int tm = (tl+tr)/2;
    int cur = -LLINF;
    if (l <= tm) cur = max(cur, query(s*2,tl,tm,l,r));
    if (r > tm) cur = max(cur, query(s*2+1,tm+1,tr,l,r));
    return cur;
}

vector<int> sub2() {
    FOR(i,0,n) {
        int ma = h[i];
        ri[i][i] = le[i][i] = h[i];
        FOR(j,i+1,n) {
            ma = max(ma,h[j]);
            ri[i][j] = ri[i][j-1]+ma;
        }
        ma = h[i];
        FORR(j,i-1,-1) {
            ma = max(ma,h[j]);
            le[i][j] = le[i][j+1]+ma;
        }
    }
    FOR(i,0,q) {
        int x = qu[i].F, y = qu[i].S;
        int res = LLINF;
        FOR(j,x,y+1) {
            res = min(res, le[j][x]+ri[j][y]-h[j]);
        }
        resv.PB(res);
    }
    return resv;
}

vector<int> sub3() {
    set<int> s;
    vector<int> v(n+5,0LL);
    int csc = 0;
    FOR(i,0,n) {
        if (h[i] == 1) csc++;
        else {
            if (i >= 1 && h[i-1] == 1) s.insert(i-1);
            csc = 0;
        }
        v[i] = csc;
        update(1,0,n-1,i,csc);
    }
    if (csc > 0) s.insert(n-1);
    s.insert(INF);
    FOR(i,0,q) {
        int l = qu[i].F, r = qu[i].S;
        int sl = *s.lower_bound(l);
        int g = 0LL;
        if (sl != INF) {
            g = query(1,0,n-1,sl+1,r);
            if (sl <= r) g = max(g, v[sl]-max(0LL,l-(sl-v[sl]+1)));
            g = max(g, v[r]-max(0LL,l-(r-v[r]+1)));
        }
        int res = g+(r-l+1-g)*2LL;
        resv.PB(res);
    }
    return resv;
}

std::vector<long long> minimum_costs(std::vector<int32_t> H, std::vector<int32_t> L, std::vector<int32_t> R) {
    n = H.size(); q = L.size();
    FOR(i,0,n) h[i] = H[i];
    FOR(i,0,q) qu.PB({L[i],R[i]});
    if (n <= 5000) return sub2();
    else return sub3();
}
