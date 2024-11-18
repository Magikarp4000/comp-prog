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

struct Node {
    int x,add;
};

const int MAXN = 3e5+1, MAXX = 1e6+1;
int n,m;
int a[MAXN], b[MAXN], cnt[MAXX];
Node st[MAXX*4+10];

void pushdown(int s) {
    st[s*2].x += st[s].add;
    st[s*2].add += st[s].add;
    st[s*2+1].x += st[s].add;
    st[s*2+1].add += st[s].add;
    st[s].add = 0;
}

void update(int s, int tl, int tr, int l, int r, int val) {
    if (l <= tl && r >= tr) {
        st[s].x += val;
        st[s].add += val;
    }
    else {
        pushdown(s);
        int tm = (tl+tr)/2;
        if (l <= tm) update(s*2,tl,tm,l,min(r,tm),val);
        if (r > tm) update(s*2+1,tm+1,tr,max(l,tm+1),r,val);
        st[s].x = max(st[s*2].x, st[s*2+1].x);
    }
}

int walk(int s, int tl, int tr, int val) {
    if (tl == tr) return tl;
    else {
        pushdown(s);
        int tm = (tl+tr)/2;
        if (st[s*2+1].x >= val) return walk(s*2+1,tm+1,tr,val);
        else return walk(s*2,tl,tm,val);
    }
}

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,m) cin >> b[i];
    FOR(i,0,n) cnt[a[i]]++;
    FOR(j,0,m) cnt[b[j]]--;
    int cur = 0;
    FORR(i,MAXX-1,-1) {
        cur += cnt[i];
        update(1,0,MAXX-1,i,i,cur);
    }
    int q; cin >> q;
    FOR(_,0,q) {
        int t,idx,val;
        cin >> t >> idx >> val;
        idx--;
        if (t == 1) {
            if (val > a[idx]) update(1,0,MAXX-1,a[idx]+1,val,1);
            else if (val < a[idx]) update(1,0,MAXX-1,val+1,a[idx],-1);
            a[idx] = val;
        }
        else {
            if (val > b[idx]) update(1,0,MAXX-1,b[idx]+1,val,-1);
            else if (val < b[idx]) update(1,0,MAXX-1,val+1,b[idx],1);
            b[idx] = val;
        }
        int res = walk(1,0,MAXX-1,1);
        if (res == 0) cout << -1;
        else cout << res;
        cout << ln;
    }
}