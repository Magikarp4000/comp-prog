#include "shoes.h"
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

const int MAXN = 2e5+5;
int st[MAXN*4+10], a[MAXN];
bool z[MAXN];
queue<int> w[MAXN];

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st[s] = val;
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = st[s*2]+st[s*2+1];
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    int tm = (tl+tr)/2;
    int cur = 0LL;
    if (l <= tm) cur += query(s*2,tl,tm,l,r);
    if (r > tm) cur += query(s*2+1,tm+1,tr,l,r);
    return cur;
}

long long count_swaps(std::vector<int32_t> v) {
    int n = v.size()/2;
    FOR(i,0,n*2) a[i] = -1;
    FOR(i,0,n*2) {
        if (!w[-v[i]+n].empty()) {
            int x = w[-v[i]+n].front();
            w[-v[i]+n].pop();
            a[x] = i;
        }
        else {
            w[v[i]+n].push(i);
        }
    }
    FOR(i,0,n*2) update(1,0,n*2-1,i,1);
    int res = 0LL;
    FOR(i,0,n*2) {
        if (z[i]) continue;
        z[i] = z[a[i]] = 1;
        update(1,0,n*2-1,i,0);
        update(1,0,n*2-1,a[i],0);
        int dist = query(1,0,n*2-1,i,a[i]);
        dist += v[i] > 0 ? 1LL : 0LL;
        res += dist;
    }
    return res;
}
