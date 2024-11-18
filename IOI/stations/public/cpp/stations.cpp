#include "stations.h"
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

const int MAXN = 2e3+5;
int timer;
vector<int> v[MAXN], w;

void dfs(int s, int pa, int d) {
    if (d == 0) w[s] = timer/2;
    timer++;
    FORX(u,v[s]) if (u != pa) dfs(u,s,d^1);
    if (d == 1) w[s] = timer/2;
    timer++;
}

vector<int> label(int n, int k, vector<int> U, vector<int> V) {
    FOR(i,0,n) v[i].clear();
    w.clear();
    timer = 0;
    FOR(i,0,n-1) v[U[i]].PB(V[i]), v[V[i]].PB(U[i]);
    w.resize(n,-1);
    dfs(0,-1,0);
    return w;
}

int find_next_station(int s, int t, vector<int> c) {
    FORX(u,c) if (t == u) return u;
    sort(ALL(c));
    int cn = c.size();
	if (s > c[0]) {
        FOR(i,1,cn-1) if (c[i] < t && c[i+1] > t) return c[i];
        if (c.back() < t && s > t) return c.back();
        return c[0];
    }
    else {
        if (s < t && c[0] > t) return c[0];
        FOR(i,1,cn) if (c[i-1] < t && c[i] > t) return c[i];
        return c.back();
    }
}
