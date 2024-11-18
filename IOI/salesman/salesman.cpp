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

const int MAXN = 5e5+5;
int n,u,d,s;
vector<PII> v[MAXN];

struct SegTree {
    int st[MAXN*4+10];
    void update(int s, int tl, int tr, int idx, int val) {
        if (tl == tr) st[s] = max(st[s], val);
        else {
            int tm = (tl+tr)/2;
            if (idx <= tm) update(s*2,tl,tm,idx,val);
            else update(s*2+1,tm+1,tr,idx,val);
            st[s] = max(st[s*2], st[s*2+1]);
        }
    }
    int query(int s, int tl, int tr, int l, int r) {
        if (l <= tl && r >= tr) return st[s];
        else {
            int tm = (tl+tr)/2;
            int cur = -LLINF;
            if (l <= tm) cur = max(cur, query(s*2,tl,tm,l,r));
            if (r > tm) cur = max(cur, query(s*2+1,tm+1,tr,l,r));
            return cur;
        }
    }
} st,st1;

signed main() {
    freopen("salesman.in","r",stdin);
    freopen("salesman.out","w",stdout);
    OPTM;
    cin >> n >> u >> d >> s;
    FOR(i,0,n) {
        int t,l,m; cin >> t >> l >> m;
        v[t].PB({l,m});
    }
    FOR(i,0,MAXN) sort(ALL(v[i]));
    FOR(i,0,MAXN*4+10) st.st[i] = st1.st[i] = -LLINF;
    st.update(1,0,MAXN-1,s,d*s), st1.update(1,0,MAXN-1,s,-u*s);
    FOR(i,0,MAXN) {
        if (v[i].empty()) continue;
        int vn = v[i].size();
        vector<int> dp(vn,-LLINF), dp1(vn,-LLINF);
        FOR(j,0,vn) {
            int l = v[i][j].F, m = v[i][j].S;
            dp[j] = max(st.query(1,0,MAXN-1,0,l)-d*l, st1.query(1,0,MAXN-1,l,MAXN-1)+u*l)+m;
            if (j > 0) dp[j] = max(dp[j], dp[j-1]-d*(v[i][j].F-v[i][j-1].F)+m);
        }
        FORR(j,vn-1,-1) {
            int l = v[i][j].F, m = v[i][j].S;
            dp1[j] = max(st.query(1,0,MAXN-1,0,l)-d*l, st1.query(1,0,MAXN-1,l,MAXN-1)+u*l)+m;
            if (j < vn-1) dp1[j] = max(dp1[j], dp1[j+1]-u*(v[i][j+1].F-v[i][j].F)+m);
        }
        FOR(j,0,vn) {
            int l = v[i][j].F;
            st.update(1,0,MAXN-1,l,max(dp[j],dp1[j])+d*l);
            st1.update(1,0,MAXN-1,l,max(dp[j],dp1[j])-u*l);
        }
    }
    int res = max(st.query(1,0,MAXN-1,0,s)-d*s, st1.query(1,0,MAXN-1,s,MAXN-1)+u*s);
    cout << res;
}