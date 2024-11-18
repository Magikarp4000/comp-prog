#include "race.h"
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

const int MAXN = 2e5+1, LOG = 19, MAXK = 1e6+5;
int n,k;
vector<int> v[MAXN], toclear;
vector<PII> v1[MAXN], add;
int sz[MAXN], mp[MAXK];
bool z[MAXN];
int res = LLINF;

int find_centroid(int s, int pa, int num) {
    FORX(u,v1[s]) {
        if (u.F == pa || z[u.F]) continue;
        if (sz[u.F] > num/2) return find_centroid(u.F,s,num);
    }
    return s;
}

void dfs(int s, int pa) {
    sz[s] = 1;
    FORX(u,v1[s]) {
        if (u.F == pa || z[u.F]) continue;
        dfs(u.F,s);
        sz[s] += sz[u.F];
    }
}

void dfs1(int s, int pa, int src, int l, int d) {
    FORX(u,v1[s]) {
        if (u.F == pa || z[u.F]) continue;
        int nl = l+u.S, nd = d+1LL;
        if (nl > k) continue;
        if (nl == k) res = min(res, nd);
        else if (nl < k) res = min(res, nd+mp[k-nl]);
        add.PB({nl,nd});
        dfs1(u.F,s,src,nl,nd);
        if (s == src) {
            FORX(y,add) {
                int cl = y.F, cd = y.S;
                mp[cl] = min(mp[cl],cd);
                toclear.PB(cl);
            }
            add.clear();
        }
    }
}

void decomp(int s, int pa) {
    FORX(u,toclear) mp[u] = LLINF;
    toclear.clear();
    dfs(s,pa);
    int c = find_centroid(s,pa,sz[s]);
    dfs1(c,-1,c,0LL,0LL);
    z[c] = 1;
    FORX(u,v1[c]) if (u.F != pa && !z[u.F]) decomp(u.F,c);
}

int32_t best_path(int32_t N, int32_t K, int32_t H[][2], int32_t L[]) {
    OPTM;
    n = N; k = K;
    FOR(i,0,n-1) {
        v1[H[i][0]].PB({H[i][1],L[i]});
        v1[H[i][1]].PB({H[i][0],L[i]});
    }
    FOR(i,0,MAXK) mp[i] = LLINF;
    decomp(0,-1);
    return res == LLINF ? -1 : res;
}
