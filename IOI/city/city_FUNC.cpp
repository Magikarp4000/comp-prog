#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9)
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

const int MAXN = 1e5+5;
int n;
UM<int,UM<int,int>> mp;
bool z[MAXN];
int comp[MAXN], sz[MAXN], dp[MAXN], num, res;
vector<pair<PII,int>> pts;
US<int> tojoin;
vector<int> v[MAXN];

void dfs(int x, int y) {
    if (z[mp[y][x]]) return;
    z[mp[y][x]] = 1;
    comp[mp[y][x]] = num;
    sz[num]++;
    if (mp[y-1].count(x)) tojoin.insert(comp[mp[y-1][x]]);
    if (mp[y].count(x+1)) dfs(x+1,y);
    if (mp[y].count(x-1)) dfs(x-1,y);
}

void dfs1(int x, int y) {
    if (z[mp[y][x]]) return;
    z[mp[y][x]] = 1;
    comp[mp[y][x]] = num;
    sz[num]++;
    if (mp[y].count(x-1)) tojoin.insert(comp[mp[y][x-1]]);
    if (mp[y+1].count(x)) dfs1(x,y+1);
    if (mp[y-1].count(x)) dfs1(x,y-1);
}

bool cmp(const pair<PII,int> &a, const pair<PII,int> &b) {
    if (a.F.S == b.F.S) return a.F.F < b.F.F;
    return a.F.S < b.F.S;
}

void dfs2(int s, int pa) {
    dp[s] = sz[s];
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs2(u,s);
        dp[s] += dp[u];
    }
}

void dfs3(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        res = (res+(dp[u]*(dp[0]-dp[u]))%INF)%INF;
        dfs3(u,s);
    }
}

void reset() {
    FOR(i,0,n+1) {
        z[i] = comp[i] = sz[i] = dp[i] = 0LL;
        v[i].clear();
    }
    num = 0LL;
}

void solve(int t) {
    if (t == 0) sort(ALL(pts));
    else sort(ALL(pts),cmp);
    FOR(i,0,n) {
        if (z[pts[i].S]) continue;
        tojoin.clear();
        if (t == 0) dfs(pts[i].F.S, pts[i].F.F);
        else dfs1(pts[i].F.S, pts[i].F.F);
        FORX(u,tojoin) {
            v[num].PB(u);
            v[u].PB(num);
        }
        num++;
    }
    dfs2(0,-1);
    dfs3(0,-1);
}

int32_t DistanceSum(int32_t N, int32_t X[], int32_t Y[]) {
    OPTM;
    n = N;
    FOR(i,0,n) {
        pts.PB({{Y[i],X[i]},i});
        mp[Y[i]][X[i]] = i;
    }
    solve(0);
    reset();
    solve(1);
    return res;
}