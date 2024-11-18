#include "candies.h"
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
int n,q;
int d[MAXN];
vector<int32_t> res;

vector<int32_t> distribute_candies(vector<int32_t> c, vector<int32_t> l, vector<int32_t> r, vector<int32_t> v) {
    n = c.size(), q = l.size();
    res.resize(n);
    FOR(i,0,q) {
        d[l[i]] += v[i];
        d[r[i]+1] += -v[i];
    }
    FOR(i,1,n) d[i] += d[i-1];
    FOR(i,0,n) res[i] = c[i] < d[i] ? c[i] : d[i];
    return res;
}
