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
int n;
int a[MAXN], b[MAXN];

void solve() {
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n+1) cin >> b[i];
    bool ok = 0;
    int res = 0, xd = LLINF;
    FOR(i,0,n) {
        res += abs(a[i]-b[i]);
        xd = min(xd, min(abs(a[i]-b[n]), abs(b[i]-b[n])));
        if (b[n] >= min(a[i],b[i]) && max(a[i],b[i]) >= b[n]) ok = 1;
    }
    res = ok ? res+1 : res+1+xd;
    cout << res << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}