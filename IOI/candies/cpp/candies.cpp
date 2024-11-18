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

vector<int> distribute_candies(vector<int> c, vector<int> l, vector<int> r, vector<int> v) {
    int n = c.size(), q = l.size();
    vector<int> a(n);
    FOR(i,0,q) FOR(j,l[i],r[i]+1) a[j] = v[i] > 0 ? min(c[j], a[j]+v[i]) : max(0, a[j]+v[i]);
    return a;
}
