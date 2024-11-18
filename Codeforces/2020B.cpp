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

int64_t mysqrt(int n) {
    int x = int64_t(sqrt(n));
    if (x*x < n) x++;
    if (x*x > n) x--;
    return x;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int n = k;
        while (n - mysqrt(n) < k) {
            n = k + mysqrt(n);
        }
        cout << n << ln;
    }
}