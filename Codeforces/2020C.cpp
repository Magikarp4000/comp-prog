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
const ll LLINF = 2e18+1;
#define int long long

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        int b,c,d; cin >> b >> c >> d;
        int a = 0;
        FOR(i,0,62) {
            int x = 1LL&(d>>i), y = 1LL&(b>>i), z = 1LL&(c>>i);
            if ((1|y)-(1&z) == x) a |= 1LL<<i;
        }
        cout << (((a|b)-(a&c)) == d ? a : -1) << ln;
    }
}