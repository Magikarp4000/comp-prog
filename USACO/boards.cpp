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

struct Board {
    int x1,y1,x2,y2;
};

const int MAXN = 2e5+10;
int en,n;
Board a[MAXN];
int st[MAXN*4+10];
vector<int> uncc;
UM<int,int> cc;
US<int> s;

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st[s] = min(st[s], val);
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = min(st[s*2], st[s*2+1]);
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    else {
        int tm =(tl+tr)/2;
        int cur = LLINF;
        if (l <= tm) cur = min(cur, query(s*2,tl,tm,l,r));
        if (r > tm) cur = min(cur, query(s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

void add(int x) {
    if (!s.count(x)) {
        s.insert(x);
        uncc.PB(x);
    }
}

bool cmp(Board &b, Board &c) {
    if (b.x1 == c.x1) return b.y1 < c.y1;
    return b.x1 < c.x1;
}

signed main() {
    freopen("boards.in","r",stdin);
    freopen("boards.out","w",stdout);
    OPTM;
    cin >> en >> n;
    FOR(i,0,n) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        add(a[i].y1);
        add(a[i].y2);
    }
    add(0); add(en);
    int vn = uncc.size();
    sort(ALL(uncc));
    FOR(i,0,vn) cc[uncc[i]] = i;
    sort(a,a+n,cmp);
    FOR(i,0,MAXN*4+10) st[i] = LLINF;
    update(1,0,n-1,0,0);
    PQ<pair<int,PLL>> pq;
    FOR(i,0,n) {
        while (!pq.empty() && -pq.top().F <= a[i].x1) {
            int ny = pq.top().S.F, val = pq.top().S.S;
            pq.pop();
            update(1,0,vn-1,cc[ny],val);
        }
        int cur = a[i].x1+a[i].y1+query(1,0,vn-1,0,cc[a[i].y1]);
        pq.push({-a[i].x2, {a[i].y2, cur-a[i].x2-a[i].y2}});
    }
    while (!pq.empty() && -pq.top().F <= en) {
        int ny = pq.top().S.F, val = pq.top().S.S;
        pq.pop();
        update(1,0,vn-1,cc[ny],val);
    }
    int res = 2*en+query(1,0,vn-1,0,cc[en]);
    cout << res;
}