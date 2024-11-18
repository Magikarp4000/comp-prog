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
#define FORX(u,arr) for (auto u : arr)
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

const int MAXN = 2e6+5, SQRT = 1420;
int n,m;
US<int> v[SQRT];

void solve() {
    cin >> n >> m;
    int res = 0;
    for (int p = 1; p*p < n; p++) {
        for (int q = 1; q*q < m; q++) {
            bool ok = 1;
            FORX(u,v[q]) if (v[p].count(u)) ok = 0;
            if (!ok) continue;
            res += min(n/p,m/q)/(p+q);
        }
    }
    cout << res << ln;
}

signed main() {
    OPTM;
    FOR(i,2,SQRT) for (int j = i; j < SQRT; j += i) v[j].insert(i);
    int T; cin >> T;
    while (T--) solve();
}