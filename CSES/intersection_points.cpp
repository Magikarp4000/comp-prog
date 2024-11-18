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

const int MAXN = 1e5+1, MAXX = 2e6+5, SHIFT = 1e6+1;
int n;
vector<pair<PII,PII>> v;
int st[MAXX*4+10];

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st[s] += val;
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = st[s*2]+st[s*2+1];
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    else {
        int tm =(tl+tr)/2;
        int cur = 0LL;
        if (l <= tm) cur += query(s*2,tl,tm,l,r);
        if (r > tm) cur += query(s*2+1,tm+1,tr,l,r);
        return cur;
    }
}

void update_(int idx, int val) {update(1,0,MAXX-1,idx,val);}
int query_(int l, int r) {return query(1,0,MAXX-1,l,r);}

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += SHIFT; x2 += SHIFT;
        if (x1 == x2) {
            v.PB({{y1,0},{x1,x2}});
            v.PB({{y2,2},{x1,x2}});
        }
        else v.PB({{y1,1},{x1,x2}});
    }
    sort(ALL(v));
    int vn = v.size();
    int res = 0LL;
    FOR(i,0,vn) {
        int x1 = v[i].S.F, x2 = v[i].S.S, t = v[i].F.S;
        if (t == 0) update_(x1,1LL);
        else if (t == 2) update_(x1,-1LL);
        else res += query_(x1,x2);
    }
    cout << res;
}