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

const int MAXN = 2e5+1, MAXR = 2.5e4+1, SQRT = 162;
int n,r,q;
vector<int> adj[MAXN];
vector<PII> reg[MAXR];
int h[MAXN];
vector<int> emp[MAXR];
int mp[MAXN], out[MAXN];
int pre[2][SQRT][MAXR];
int timer;
int sz[MAXR], rmp[MAXR];

void dfs(int s) {
    emp[h[s]].PB(s);
    mp[s] = timer;
    timer++;
    FORX(u,adj[s]) {
        dfs(u);
    }
    out[s] = timer;
}

int calc(int a, int b) {
    int i = 0, j = 0, res = 0;
    int an = reg[a].size(), bn = sz[b];
    while (i < an && j < bn) {
        if (reg[a][i].F < mp[emp[b][j]]) i++;
        else {
            res += reg[a][i].S;
            j++;
        }
    }
    return res;
}

signed main() {
    OPTM;
    cin >> n >> r >> q >> h[1];
    int blk = sqrt(n+.0)+1;
    FOR(i,2,n+1) {
        int x;
        cin >> x >> h[i];
        adj[x].PB(i);
    }
    dfs(1);
    FOR(i,1,r+1) sz[i] = emp[i].size();
    FOR(i,1,r+1) {
        vector<PII> v;
        FORX(u,emp[i]) {
            v.PB({mp[u],1});
            v.PB({out[u],-1});
        }
        sort(ALL(v));
        int vn = v.size();
        int j = 0, cur = 0;
        while (j < vn) {
            if (v[j].F-1 >= 0) reg[i].PB({v[j].F-1,cur});
            cur += v[j].S;
            while (j+1 < vn && v[j+1].F == v[j].F) cur += v[++j].S;
            j++;
        }
        reg[i].PB({n-1,cur});
    }
    int idx = 0;
    FOR(i,1,r+1) {
        if (sz[i] >= blk) {
            rmp[i] = idx;
            FOR(j,1,r+1) {
                if (i == j) continue;
                pre[0][idx][j] = calc(i,j);
                pre[1][idx][j] = calc(j,i);
            }
            idx++;
        }
    }
    FOR(_,0,q) {
        int a,b; cin >> a >> b;
        if (sz[a] >= blk) cout << pre[0][rmp[a]][b];
        else if (sz[b] >= blk) cout << pre[1][rmp[b]][a];
        else cout << calc(a,b);
        cout << endl;
    }
}