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
        int n,k; cin >> n >> k;
        int j = k;
        if (k != 1) {
            while (j < n) j *= k;
        }
        int cnt = 0;
        while (n >= 0) {
            if (j == 1) {
                cnt += n;
                break;
            }
            while (n-j >= 0) n -= j, cnt++;
            if (n == 0) break;
            j /= k;
        }
        cout << cnt << ln;
    }
}