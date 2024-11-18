#include "horses.h"
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

const int MAXN = 5e5+10, LOG = 30;
const ll MAXX = 1e9;
int n;
ll x[MAXN], y[MAXN];
set<int> a;
ll st[MAXN*4], st1[MAXN*4];

void build(int s, int tl, int tr) {
    if (tl == tr) st[s] = y[tl];
    else {
        int tm = (tl+tr)/2;
        build(s*2,tl,tm);
        build(s*2+1,tm+1,tr);
        st[s] = max(st[s*2], st[s*2+1]);
    }
}

void update(int s, int tl, int tr, int idx, ll val) {
    if (tl == tr) st[s] = val;
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = max(st[s*2], st[s*2+1]);
    }
}

ll query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    else {
        int tm = (tl+tr)/2;
        ll cur = -INF;
        if (l <= tm) cur = max(cur, query(s*2,tl,tm,l,r));
        if (r > tm) cur = max(cur, query(s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

void build1(int s, int tl, int tr) {
    if (tl == tr) st1[s] = x[tl];
    else {
        int tm = (tl+tr)/2;
        build1(s*2,tl,tm);
        build1(s*2+1,tm+1,tr);
        st1[s] = (st1[s*2]*st1[s*2+1])%INF;
    }
}

void update1(int s, int tl, int tr, int idx, ll val) {
    if (tl == tr) st1[s] = val;
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update1(s*2,tl,tm,idx,val);
        else update1(s*2+1,tm+1,tr,idx,val);
        st1[s] = (st1[s*2]*st1[s*2+1])%INF;
    }
}

ll query1(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st1[s];
    else {
        int tm = (tl+tr)/2;
        ll cur = 1ll;
        if (l <= tm) cur = (cur*query1(s*2,tl,tm,l,r))%INF;
        if (r > tm) cur = (cur*query1(s*2+1,tm+1,tr,l,r))%INF;
        return cur;
    }
}

int calc() {
    vector<int> v;
    int cnt = 0;
    for (auto it = a.rbegin(); it != a.rend(); it++) {
    	v.PB(*it);
    	cnt++;
    	if (cnt >= LOG) break;
    }
    //v.PB(0);
    reverse(ALL(v));
    // FORX(u,v) cout << u << ' ';
    // cout << ln;
    int vn = v.size();
    ll xval = 1, yval = 0, cur = -INF, idx = -1;
    FOR(i,0,vn) {
        int en = i == vn-1 ? n-1 : v[i+1]-1;
        xval *= x[v[i]];
        yval = query(1,0,n-1,v[i],en);
        if (xval > MAXX || xval*yval > cur) {
            idx = i;
            cur = yval;
            xval = 1;
        }
    }
    int en = idx == vn-1 ? n-1 : v[idx+1]-1;
    // cout << v[idx] << ln;
    ll res = (query1(1,0,n-1,0,v[idx])*query(1,0,n-1,v[idx],en))%INF;
    //ll res = 0;
    return res;
}

int init(int N, int X[], int Y[]) {
    OPTM;
    n = N;
    FOR(i,0,n) {
        x[i] = X[i];
        y[i] = Y[i];
    }
    a.insert(0);
    build(1,0,n-1);
    build1(1,0,n-1);
    FOR(i,0,n) if (x[i] > 1) a.insert(i);
    return calc();
}

int updateX(int pos, int val) {	
    update1(1,0,n-1,pos,val);
    x[pos] = val;
    if (val == 1 && a.count(pos) && pos != 0) a.erase(pos);
    if (val > 1) a.insert(pos);
    return calc();
}

int updateY(int pos, int val) {
    update(1,0,n-1,pos,val);
    y[pos] = val;
    return calc();
}
