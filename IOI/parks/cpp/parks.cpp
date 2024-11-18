#include "parks.h"
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

const int MAXN = 2e5+5;
int n;
UM<int,int> col[MAXN];
vector<PII> pts,bch;
vector<pair<PII,PII>> rds;
vector<int> v[MAXN];
bool z[MAXN];

void add(int a, int b, int idx, int wt) {
    rds.PB({{wt,idx},{a,b}});
    v[a].PB(b);
    v[b].PB(a);
}

void dfs(int s) {
    if (z[s]) return;
    z[s] = 1;
    FORX(u,v[s]) dfs(u);
}

bool cmp(const PII &a, const PII &b) {
    if (a.S == b.S) return a.F < b.F;
    return a.S < b.S;
}

int construct_roads(std::vector<int> X, std::vector<int> Y) {
    n = X.size();
    FOR(i,0,n) pts.PB({X[i],Y[i]});
    FOR(i,0,n) col[X[i]][Y[i]] = i;
    int idx = 0;
    FOR(i,0,n) {
        int x = pts[i].F, y = pts[i].S;
        int wt = x == 4 ? 2 : 0;
        if (col[x].count(y+2)) add(i,col[x][y+2],idx++,wt);
        if (col[x+2].count(y)) add(i,col[x+2][y],idx++,1);
    }
    dfs(0);
    // FOR(i,0,n) {
    //     cout << i << ": ";
    //     FORX(u,v[i]) cout << u << " ";
    //     cout << ln;
    // }
    // FOR(i,0,n) cout << z[i] << " ";
    // cout << ln;
    FOR(i,0,n) if (!z[i]) return 0;
    int m = rds.size();
    bch.resize(m);
    FORX(u,rds) {
        int x1 = pts[u.F.F].F, y1 = pts[u.F.F].S, x2 = pts[u.F.S].F, y2 = pts[u.F.S].S, idx = u.S;
        if (x1 == x2) {
            if (x1 == 2) bch[idx] = {1,(y1+y2)/2};
            else bch[idx] = {5,(y1+y2)/2};
        }
        else {
            bch[idx] = {(x1+x2)/2, y1-1};
        }
    }
    vector<int> ru,rv,ra,rb;
    FORX(u,rds) ru.PB(u.F.F), rv.PB(u.F.S);
    FORX(u,bch) ra.PB(u.F), rb.PB(u.S);
    build(ru,rv,ra,rb);
    return 1;
}
