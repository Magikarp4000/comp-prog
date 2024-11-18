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

const int MAXN = 2e5+1;
int n,k;
int a[MAXN];

bool check(int x) {
    vector<int> v(n,0), p(n+1,0);
    FOR(i,0,n) v[i] = a[i] >= x ? 1 : -1;
    FOR(i,1,n+1) p[i] = p[i-1]+v[i-1];
    int res = p[k], cur = p[k];
    FOR(i,k,n) {
        cur = max(cur+v[i], p[i+1]-p[i-k+1]);
        res = max(res, cur);
    }
    return (res > 0);
}

signed main() {
    OPTM;
    cin >> n >> k;
    FOR(i,0,n) cin >> a[i];
    int l = 1, r = 2e5+1;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l;
}