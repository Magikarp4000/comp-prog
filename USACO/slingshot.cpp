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

const int MAXN = 3e5+1;
int st[MAXN*4+10], st1[MAXN*4+10], st2[MAXN*4+10], st3[MAXN*4+10];
int n,m;
UM<int,int> cc;
vector<int> uncc;
vector<pair<PLL,PLL>> v;
int res[MAXN];

void update(int tree[], int s, int tl, int tr, int idx, int val) {
    if (tl == tr) tree[s] = min(tree[s],val);
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(tree,s*2,tl,tm,idx,val);
        else update(tree,s*2+1,tm+1,tr,idx,val);
        tree[s] = min(tree[s*2], tree[s*2+1]);
    }
}

int query(int tree[], int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return tree[s];
    else {
        int tm = (tl+tr)/2;
        int cur = LLINF;
        if (l <= tm) cur = min(cur,query(tree,s*2,tl,tm,l,r));
        if (r > tm) cur = min(cur,query(tree,s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

US<int> s;
void add(int x) {
    if (!s.count(x)) {
        s.insert(x);
        uncc.PB(x);
    }
}

signed main() {
    freopen("slingshot.in","r",stdin);
    freopen("slingshot.out","w",stdout);
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) {
        int a,b,t; cin >> a >> b >> t;
        v.PB({{a,b},{t,i}});
        add(b);
    }
    FOR(i,0,m) {
        int a,b; cin >> a >> b;
        v.PB({{a,b},{-1,i}});
        add(b);
        res[i] = abs(b-a);
    }
    sort(ALL(uncc));
    sort(ALL(v));
    int cn = uncc.size(), vn = v.size();
    FOR(i,0,cn) cc[uncc[i]] = i;
    FOR(i,0,MAXN*4+10) st[i] = st1[i] = st2[i] = st3[i] = LLINF;
    FOR(i,0,vn) {
        int a = v[i].F.F, b = v[i].F.S, t = v[i].S.F, idx = v[i].S.S;
        if (t != -1) {
            update(st,1,0,cn-1,cc[b],t-a-b);
            update(st1,1,0,cn-1,cc[b],t-a+b);
        }
        else {
            res[idx] = min(res[idx], min(a+b+query(st,1,0,cn-1,0,cc[b]), a-b+query(st1,1,0,cn-1,cc[b],cn-1)));
        }
    }
    FORR(i,vn-1,-1) {
        int a = v[i].F.F, b = v[i].F.S, t = v[i].S.F, idx = v[i].S.S;
        if (t != -1) {
            update(st2,1,0,cn-1,cc[b],t+a+b);
            update(st3,1,0,cn-1,cc[b],t+a-b);
        }
        else {
            res[idx] = min(res[idx], min(-a-b+query(st2,1,0,cn-1,cc[b],cn-1), -a+b+query(st3,1,0,cn-1,0,cc[b])));
        }
    }
    FOR(i,0,m) cout << res[i] << ln;
}