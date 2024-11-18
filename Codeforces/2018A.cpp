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

const int MAXN = 2e5+5;
int n,k;
int a[MAXN];

int solve() {
    cin >> n >> k;
    FOR(i,0,n) cin >> a[i];
    int sum = 0, mx = 0;
    FOR(i,0,n) sum += a[i], mx = max(mx, a[i]);
    int res = 0;
    FOR(i,1,n+1) {
        int x = (sum+k)/i;
        int newsum = x*i;
        if (newsum < sum || mx > x) continue;
        if (x*n < newsum) continue;
        res = max(res, i);
    }
    return res;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << solve() << ln;
}