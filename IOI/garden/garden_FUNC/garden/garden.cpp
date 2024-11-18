#include "garden.h"
#include "gardenlib.h"
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

const int MAXN = 3e5+10;
int n,m,tgt,q;
vector<PII> adj[MAXN];
int f[MAXN], pos[2], d[MAXN][2], cnt[MAXN][2], start[2], len[2];
int res[MAXN], rogue[MAXN];
vector<int> r[MAXN];
bool z[MAXN][2], cyc[MAXN][2], z1[MAXN][2];

int dfs(int s, int idx) {
    int num = 0;
    while (!z[s][idx]) {
        z[s][idx] = 1;
        s = f[s];
        num++;
    }
    return s;
}

int dfs1(int s, int idx) {
    bool begun = 0;
    int num = 0;
    while (!begun || s != start[idx]) {
        begun = 1;
        if (s == tgt) pos[0] = num;
        else if (s == tgt+n) pos[1] = num;
        cyc[s][idx] = 1;
        num++;
        s = f[s];
    }
    return num;
}

void dfs2(int s, int idx) {
    if (pos[idx] == -1) return;
    bool begun = 0;
    int num = 0;
    while (!begun || s != start[idx]) {
        begun = 1;
        d[s][idx] = pos[idx] >= num ? pos[idx]-num : pos[idx]-num+len[idx];
        num++;
        s = f[s];
    }
}

void dfs3(int s, int idx) {
    if (pos[idx] == -1) return;
    stack<int> st;
    while (d[s][idx] == -1) {
        st.push(s);
        s = f[s];
    }
    int num = d[s][idx]+1;
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        d[cur][idx] = num++;
    }
}

void dfs4(int s, int dist) {
    if (s < n) rogue[dist]++;
    FORX(u,r[s]) dfs4(u,dist+1);
}

void dfs5(int s, int idx) {
    if (z1[s][idx]) return;
    z1[s][idx] = 1;
    FORX(u,r[s]) dfs5(u,idx);
    dfs5(f[s],idx);
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]) {
    n = N, m = M, tgt = P, q = Q;
    FOR(i,0,m) {
        int a = R[i][0], b = R[i][1];
        adj[a].PB({i,b});
        adj[b].PB({i,a});
    }
    FOR(i,0,n) sort(ALL(adj[i]));
    FOR(i,0,n) {
        int best = adj[i][0].S;
        if (adj[best][0].S == i) f[i] = best+n;
        else f[i] = best;
        int best1 = adj[i].size() <= 1 ? best : adj[i][1].S;
        if (adj[best1][0].S == i) f[i+n] = best1+n;
        else f[i+n] = best1;
    }
    FOR(i,0,n*2) r[f[i]].PB(i);
    FOR(i,0,n*2) {
        FOR(j,0,2) d[i][j] = -1;
    }
    pos[0] = pos[1] = -1;
    len[0] = len[1] = 1;
    FOR(j,0,2) {
        int cur = j == 0 ? tgt : tgt+n;
        dfs5(cur,j);
        start[j] = dfs(cur,j);
        len[j] = dfs1(start[j],j);
        dfs2(start[j],j);
        FOR(i,0,n*2) if (z1[i][j]) dfs3(i,j);
        if (!cyc[cur][j]) dfs4(cur,0);
    }
    vector<int> val[2];
    FOR(j,0,2) {
        FOR(i,0,n) {
            if (d[i][j] != -1) {
                val[j].PB(d[i][j]);
                cnt[d[i][j]%len[j]][j]++;
            }
        }
        sort(ALL(val[j]), greater<int>());
    }
    int v0n = val[0].size(), v1n = val[1].size();
    vector<PII> qrs;
    FOR(i,0,q) qrs.PB({G[i],i});
    sort(ALL(qrs), greater<PII>());
    int j = 0, k = 0;
    FOR(i,0,q) {
        int x = qrs[i].F, idx = qrs[i].S;
        while (j < v0n && val[0][j] > x) cnt[val[0][j++]%len[0]][0]--;
        while (k < v1n && val[1][k] > x) cnt[val[1][k++]%len[1]][1]--;
        int extra = x >= MAXN ? 0 : rogue[x];
        res[idx] = cnt[x%len[0]][0]+cnt[x%len[1]][1]+extra;
    }
    FOR(i,0,q) answer(res[i]);
}


