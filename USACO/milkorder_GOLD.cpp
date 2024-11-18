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
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 1e5+1, MAXM = 5e4+1;
int n,m;
vector<PII> a[MAXM];
int z[MAXN], ind[MAXN];
bool ok = 1;
vector<int> v[MAXN];

void dfs(int s, vector<int> v[]) {
    if (z[s] == 2) return;
    if (z[s] == 1) {
        ok = 0;
        return;
    }
    z[s] = 1;
    FORX(u,v[s]) dfs(u,v);
    z[s] = 2;
}

bool check(int cur) {
    ok = 1;
    FOR(i,1,n+1) {
        v[i].clear();
        z[i] = 0;
    }
    FOR(i,0,cur) FORX(u,a[i]) v[u.F].PB(u.S);
    FOR(i,1,n+1) dfs(i,v);
    if (!ok) return 0;
    return 1;
}

void solve(int x) {
    FOR(i,1,n+1) {
        v[i].clear();
        z[i] = 0;
    }
    FOR(i,0,x) {
        FORX(u,a[i]) {
            v[u.F].PB(u.S);
            ind[u.S]++;
        }
    }
    int num = 0;
    PQ<int> pq;
    FOR(i,1,n+1) if (ind[i] == 0) pq.push(-i);
    while (!pq.empty()) {
        int s = -pq.top();
        pq.pop();
        if (z[s]) continue;
        z[s] = 1;
        if (num != n-1) cout << s << " ";
        else cout << s;
        num++;
        FORX(u,v[s]) {
            ind[u]--;
            if (ind[u] == 0) pq.push(-u);
        }
    }
}

signed main() {
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    OPTM;
    cin >> n >> m;
    FOR(i,0,m) {
        int k; cin >> k;
        int x;
        if (k > 0) cin >> x;
        FOR(j,1,k) {
            int nx; cin >> nx;
            a[i].PB({x,nx});
            x = nx;
        }
    }
    int l = 0, r = m;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    solve(l);
}