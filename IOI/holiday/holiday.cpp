#include "holiday.h"
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
    int x,cnt;
};

const int MAXN = 5e5+5;
int n,d,start;
int a[MAXN];
Node st[MAXN*4+10];
vector<PII> v;
int perm[MAXN], lsum[MAXN], rsum[MAXN], le[MAXN], ri[MAXN];

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        if (val == -1) {
            st[s].x = 0LL;
            st[s].cnt = 0;
        }
        else {
            st[s].x = val;
            st[s].cnt = 1;
        }
    }
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s].x = st[s*2].x+st[s*2+1].x;
        st[s].cnt = st[s*2].cnt+st[s*2+1].cnt;
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s].x;
    else {
        int tm = (tl+tr)/2;
        int cur = 0LL;
        if (l <= tm) cur += query(s*2,tl,tm,l,r);
        if (r > tm) cur += query(s*2+1,tm+1,tr,l,r);
        return cur;
    }
}

int walk(int s, int tl, int tr, int pre, int val) {
    if (tl == tr) return query(1,0,n-1,tl,n-1);
    int tm = (tl+tr)/2;
    if (pre+st[s*2+1].cnt >= val) return walk(s*2+1,tm+1,tr,pre,val);
    else return walk(s*2,tl,tm,pre+st[s*2+1].cnt,val);
}

void solve(int x, int dx, int l, int r) {
    FORR(i,r,l-1) {
        update(1,0,n-1,perm[i],a[i]);
        if (x-(start-i) <= 0) continue;
        int cur = walk(1,0,n-1,0LL,x-(start-i));
        if (cur > lsum[x]) {
            lsum[x] = cur;
            le[x] = i;
        }
    }
    if (dx == 1) return;
    int ndx = dx/2;
    FOR(i,l,le[x]+1) update(1,0,n-1,perm[i],-1);
    solve(x+ndx,ndx,l,le[x]);
    FOR(i,l,r+1) update(1,0,n-1,perm[i],-1);
    solve(x-ndx,ndx,le[x],r);
}

void solve1(int x, int dx, int l, int r) {
    FOR(i,l,r+1) {
        update(1,0,n-1,perm[i],a[i]);
        if (x-(i-start-1) <= 0) continue;
        int cur = walk(1,0,n-1,0LL,x-(i-start-1));
        if (cur > rsum[x]) {
            rsum[x] = cur;
            ri[x] = i;
        }
    }
    if (dx == 1) return;
    int ndx = dx/2;
    FOR(i,ri[x],r+1) update(1,0,n-1,perm[i],-1);
    solve1(x+ndx,ndx,ri[x],r);
    FOR(i,l,r+1) update(1,0,n-1,perm[i],-1);
    solve1(x-ndx,ndx,l,ri[x]);
}

long long findMaxAttraction(int32_t N, int32_t S, int32_t D, int32_t A[]) {
    n = N, d = D, start = S;
    FOR(i,0,n) {
        a[i] = A[i];
        v.PB({a[i],i});
    }
    sort(ALL(v));
    FOR(i,0,n) perm[v[i].S] = i;
    FOR(i,0,MAXN) lsum[i] = rsum[i] = -LLINF;
    int tmp = d, lg = -1;
    while (tmp) lg++, tmp >>= 1;
    int mid = 1<<lg;
    solve(mid,mid,0,start);
    if (start == n-1) return lsum[d];
    FOR(i,0,n) update(1,0,n-1,perm[i],-1);
    solve1(mid,mid,start+1,n-1);
    int res = 0LL;
    FOR(i,1,d+1) {
        int rem = d-i-(start+1-le[i]);
        int c = rem > 0LL ? rsum[rem] : 0LL;
        res = max(res, lsum[i]+c);
        if (i == 1) continue;
        rem = d-i-(ri[i-1]-start);
        c = rem > 0LL ? lsum[rem] : 0LL;
        res = max(res, rsum[i-1]+c);
    }
    return res;
}
