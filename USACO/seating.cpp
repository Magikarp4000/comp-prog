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
    int x,pre,suf,lz;
};

const int MAXN = 5e5+1;
int n,m;
Node st[MAXN*4+10];

void pushdown(int s, int tl, int tr) {
    if (st[s].lz == -1) return;
    int tm = (tl+tr)/2;
    st[s*2].pre = st[s*2].suf = st[s*2].x = st[s].lz*(tm-tl+1);
    st[s*2+1].pre = st[s*2+1].suf = st[s*2+1].x = st[s].lz*(tr-tm);
    st[s*2].lz = st[s*2+1].lz = st[s].lz;
    st[s].lz = -1;
}

void update(int s, int tl, int tr, int l, int r, int val) {
    if (l <= tl && r >= tr) {
        st[s].pre = st[s].suf = st[s].x = val*(tr-tl+1);
        st[s].lz = val;
    }
    else {
        pushdown(s,tl,tr);
        int tm = (tl+tr)/2;
        if (l <= tm) update(s*2,tl,tm,l,min(tm,r),val);
        if (r > tm) update(s*2+1,tm+1,tr,max(tm+1,l),r,val);
        st[s].pre = st[s*2].pre == tm-tl+1 ? st[s*2].pre+st[s*2+1].pre : st[s*2].pre;
        st[s].suf = st[s*2+1].suf == tr-tm ? st[s*2+1].suf+st[s*2].suf : st[s*2+1].suf;
        st[s].x = max(max(st[s*2].x, st[s*2+1].x), st[s*2].suf+st[s*2+1].pre);
    }
}

int walk(int s, int tl, int tr, int val) {
    if (st[1].x < val) return -1;
    if (tl == tr) return tl;
    else {
        pushdown(s,tl,tr);
        int tm = (tl+tr)/2;
        if (st[s*2].x >= val) return walk(s*2,tl,tm,val);
        else if (st[s*2].suf+st[s*2+1].pre >= val) return tm-st[s*2].suf+1;
        else return walk(s*2+1,tm+1,tr,val);
    }
}

void update_(int l, int r, int val) {update(1,0,n-1,l,r,val);}
int walk_(int val) {return walk(1,0,n-1,val);}

signed main() {
    freopen("seating.in","r",stdin);
    freopen("seating.out","w",stdout);
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) st[i].lz = -1;
    update_(0,n-1,1);
    int res = 0;
    FOR(_,0,m) {
        char c; cin >> c;
        if (c == 'A') {
            int p; cin >> p;
            int ans = walk_(p);
            if (ans == -1) res++;
            else update_(ans,ans+p-1,0);
        }
        else {
            int a,b; cin >> a >> b;
            a--; b--;
            update_(a,b,1);
        }
    }
    cout << res;
}