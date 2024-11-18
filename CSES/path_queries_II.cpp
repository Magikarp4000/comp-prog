#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int MAXN = 2e5+5;
int n,q;
int val[MAXN];
int sz[MAXN], d[MAXN], p[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int st[MAXN*4+10];
vector<int> v[MAXN];
int timer;

void dfs(int s, int pa) {
    sz[s] = 1;
    int ma = -INF;
    FORX(u,v[s]) {
        if (u == pa) continue;
        p[u] = s;
        d[u] = d[s]+1;
        dfs(u,s);
        sz[s] += sz[u];
        if (sz[u] > ma) ma = sz[u], heavy[s] = u;
    }
}

void decomp(int s, int h) {
    head[s] = h, pos[s] = timer++;
    if (heavy[s] != -1) decomp(heavy[s],h);
    FORX(u,v[s]) {
        if (u == p[s] || u == heavy[s]) continue;
        decomp(u,u);
    } 
}

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
    if (l <= tl && r >= tr) return st[s];
    else {
        int tm = (tl+tr)/2;
        int cur = 0;
        if (l <= tm) cur = max(cur, query(s*2,tl,tm,l,r));
        if (r > tm) cur = max(cur, query(s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

int hld_query(int a, int b) {
    int ans = 0;
    while (head[a] != head[b]) {
        if (d[head[a]] > d[head[b]]) swap(a,b);
        ans = max(ans, query(1,0,n-1,pos[head[b]],pos[b]));
        b = p[head[b]];
    }
    if (d[a] > d[b]) swap(a,b);
    ans = max(ans, query(1,0,n-1,pos[a],pos[b]));
    return ans;
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) cin >> val[i];
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        v[a].PB(b);
        v[b].PB(a);
    }
    FOR(i,0,n) heavy[i] = head[i] = -1;
    dfs(0,-1);
    decomp(0,0);
    FOR(i,0,n) update(1,0,n-1,pos[i],val[i]);
    FOR(_,0,q) {
        int t; cin >> t;
        if (t == 1) {
            int s,x; cin >> s >> x;
            s--;
            update(1,0,n-1,pos[s],x);
        }
        else {
            int a,b; cin >> a >> b;
            a--; b--;
            cout << hld_query(a,b) << " ";
        }
    }
}