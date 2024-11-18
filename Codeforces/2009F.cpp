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

const int MAXN = 2e5+5;
int n,q;
int a[MAXN], p[MAXN];

int sum(int l, int r) {
    if (r < 0) return 0;
    return p[r+1] - p[l];
}

int calc(int shift, int l, int r) {
    if (r < n-shift || l >= n-shift) return sum((l+shift)%n, (r+shift)%n);
    else return sum((l+shift)%n, n-1) + sum(0, (r+shift)%n);
}

void solve() {
    cin >> n >> q;
    FOR(i,0,n) cin >> a[i];
    FOR(i,1,n+1) p[i] = p[i-1] + a[i-1];
    FOR(_,0,q) {
        int l,r; cin >> l >> r;
        l--; r--;
        int whole = max(0ll, r/n - l/n - 1ll);
        int res = l/n == r/n ? calc(l/n, l%n, r%n) : whole*p[n] + calc(l/n, l%n, n-1) + calc(r/n, 0, r%n);
        cout << res << ln;
    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}