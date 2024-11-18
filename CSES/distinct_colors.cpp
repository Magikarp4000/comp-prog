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

const int MAXN = 2e5+1;
int n;
vector<int> v[MAXN];
vector<int> tour;
int c[MAXN], sz[MAXN], res[MAXN];
UM<int,int> mp;
int st[MAXN*4+1];

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
    else {
        int tm = (tl+tr)/2;
        int cur = 0;
        if (l <= tm) cur += query(s*2,tl,tm,l,r);
        if (r > tm) cur += query(s*2+1,tm+1,tr,l,r);
        return cur;
    }
}

void dfs(int s, int pa) {
    sz[s] = 1;
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        sz[s] += sz[u];
    }
    tour.PB(s);
}

signed main() {
    OPTM;
    cin >> n;
    FOR(i,1,n+1) cin >> c[i];
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(1,-1);
    FOR(i,0,n) {
        if (mp.count(c[tour[i]])) {
            int pos = mp[c[tour[i]]];
            update(1,0,n-1,pos,0);
        }
        mp[c[tour[i]]] = i;
        update(1,0,n-1,i,1);
        res[tour[i]] = query(1,0,n-1,i-sz[tour[i]]+1,i);
    }
    FOR(i,1,n+1) cout << res[i] << ' ';
}
