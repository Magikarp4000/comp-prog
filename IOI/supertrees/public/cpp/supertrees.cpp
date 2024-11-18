// goofy ahh

#include "supertrees.h"
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

const int MAXN = 1e3+5;
int n,wn;
int a[MAXN][MAXN], d[MAXN], comp[MAXN];
vector<int> v[MAXN], v1[MAXN], goofy, w;
vector<vector<int>> b;
bool vis[MAXN], z[MAXN];

bool bfs(int start) {
    queue<int> q;
    FOR(i,0,wn) d[w[i]] = INF;
    d[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        FORX(u,v[s]) {
            if (d[s] == 1 && d[u] == 1) {
                goofy = {start,s,u};
                return 1;
            }
            if (d[s]+1 < 2 && d[s]+1 < d[u]) {
                d[u] = d[s]+1;
                q.push(u);
            }
        }
    }
    return 0;
}

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = 1;
    w.PB(s);
    FORX(u,v1[s]) dfs(u);
}

bool solve() {
    goofy.clear();
    FOR(i,0,wn) if (bfs(w[i])) break;
    if (goofy.empty()) {
        FOR(i,0,wn) FOR(j,i+1,wn) if (a[w[i]][w[j]] == 2) return 0;
        FOR(i,0,wn-1) b[w[i]][w[i+1]] = b[w[i+1]][w[i]] = 1;
        return 1;
    }
    FORX(u,goofy) z[u] = 1;
    FOR(i,0,wn) {
        if (z[w[i]]) continue;
        bool ok = 1;
        FORX(u,goofy) if (a[w[i]][u] != 2) ok = 0;
        if (ok) z[w[i]] = 1, goofy.PB(w[i]);
    }
    int gn = goofy.size();
    FOR(i,0,wn) comp[w[i]] = -1;
    FORX(u,goofy) comp[u] = u;
    FOR(i,0,wn) {
        if (z[w[i]]) continue;
        FOR(j,0,wn) {
            if (i == j) continue;
            if (a[w[i]][w[j]] == 1 && z[w[j]]) {
                comp[w[i]] = w[j];
                break;
            }
        }
    }
    FOR(i,0,wn) {
        FOR(j,0,wn) {
            if (i == j) continue;
            if (a[w[i]][w[j]] == 2 && comp[w[i]] == comp[w[j]]) return 0;
            if (a[w[i]][w[j]] == 1 && comp[w[i]] != comp[w[j]]) return 0;
        }
    }
    FOR(i,0,gn) b[goofy[i]][goofy[(i+1)%gn]] = b[goofy[(i+1)%gn]][goofy[i]] = 1;
    FOR(i,0,wn) if (!z[w[i]]) b[w[i]][comp[w[i]]] = b[comp[w[i]]][w[i]] = 1;
    return 1;
}

bool precheck() {
    wn = w.size();
    FOR(i,0,wn) {
        FOR(j,0,wn) {
            if (a[w[i]][w[j]] == 0) return 0;
        }
    }
    return 1;
}

void reset() {
    FORX(u,w) v[u].clear();
    w.clear();
}

int construct(vector<vector<int>> P) {
	n = P.size();
    b.resize(n,vector<int>(n));
    FOR(i,0,n) FOR(j,0,n) a[i][j] = P[i][j];
    FOR(i,0,n) {
        FOR(j,i+1,n) {
            if (a[i][j] == 3) return 0;
            if (a[i][j]) v1[i].PB(j), v1[j].PB(i);
            if (a[i][j] == 2) v[i].PB(j), v[j].PB(i);
        }
    }
    FOR(i,0,n) {
        if (vis[i]) continue;
        reset();
        dfs(i);
        if (!precheck()) return 0;
        if (!solve()) return 0;
    }
    build(b);
    return 1;
}
