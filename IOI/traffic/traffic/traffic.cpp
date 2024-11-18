#include "traffic.h"
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

const int MAXN = 1e6+5;
int n;
int p[MAXN], dp[MAXN];
vector<int> v[MAXN];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        p[u] = s;
        dfs(u,s);
        dp[s] += dp[u];
    }
}

int LocateCentre(int N, int P[], int s[], int d[]) {
    n = N;
    FOR(i,0,n) dp[i] = P[i];
    FOR(i,0,n-1) {
        v[s[i]].PB(d[i]);
        v[d[i]].PB(s[i]);
    }
    p[0] = -1;
    dfs(0,-1);
    int res = INF, idx = -1;
    FOR(i,0,n) {
        int cur = -INF;
        FORX(u,v[i]) {
            if (u == p[i]) cur = max(cur, dp[0]-dp[i]);
            else cur = max(cur, dp[u]);
        }
        if (cur < res) res = cur, idx = i;
    }
    return idx;
}
