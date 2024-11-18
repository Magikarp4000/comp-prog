#include "werewolf.h"
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

const int MAXN = 2e5+5;
vector<int> v[MAXN];
int n,m,Q;
bool z[MAXN], z1[MAXN];

void reset() {
    FOR(i,0,n) {
        z[i] = z1[i] = 0;
    }
}

bool solve(int sta, int en, int l, int r) {
    queue<int> q;
    q.push(sta);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        z[s] = 1;
        FORX(u,v[s]) {
            if (z[u] || u < l) continue;
            q.push(u);
        }
    }
    q.push(en);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        z1[s] = 1;
        FORX(u,v[s]) {
            if (z1[u] || u > r) continue;
            q.push(u);
        }
    }
    FOR(i,0,n) if (z[i] && z1[i]) return 1;
    return 0;
}

std::vector<int> check_validity(int N, std::vector<int> X, std::vector<int> Y,
                                std::vector<int> S, std::vector<int> E,
                                std::vector<int> L, std::vector<int> R) {
    n = N, m = X.size(), Q = S.size();
    FOR(i,0,m) {
        v[X[i]].PB(Y[i]);
        v[Y[i]].PB(X[i]);
    }
    vector<int> res;
    FOR(i,0,Q) {
        reset();
        bool ans = solve(S[i],E[i],L[i],R[i]);
        res.PB(ans);
    }
    return res;
}
