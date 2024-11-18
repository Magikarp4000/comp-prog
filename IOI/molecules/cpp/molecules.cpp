#include "molecules.h"
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
#define int long long

const int MAXN = 2e5+5;
int u,l,n;
int pre[MAXN], suf[MAXN];
vector<PII> v;

vector<int32_t> solve(int x) {
    vector<int32_t> res;
    FOR(i,x,n+1) {
        if (pre[i]-pre[i-x] >= l && pre[i]-pre[i-x] <= u) {
            FOR(j,i-x,i) res.PB(v[j].S);
            return res;
        }
    }
    return res;
}

std::vector<int32_t> find_subset(int32_t L, int32_t U, std::vector<int32_t> w) {
    l = L, u = U, n = w.size();
    FOR(i,0,n) v.PB({w[i],i});
    sort(ALL(v));
    FOR(i,0,n) pre[i+1] = pre[i]+v[i].F;
    FORR(i,n-1,-1) suf[i+1] = suf[i+2]+v[i].F;
    FOR(i,0,n) {
        if (pre[i+1] <= u && suf[n-i] >= l) return solve(i+1);
    }
    return vector<int32_t>();
}
