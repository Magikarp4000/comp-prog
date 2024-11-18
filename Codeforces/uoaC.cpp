#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int(1e9+7)
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,s,n) for (int i = s; i > n; i--)
#define ln '\n'
#define int long long
const long long LLINF = 1e18;

const int MAXN = 2e5+5;
int a[MAXN];

void solve() {
    int n; cin >> n;
    FOR(i,0,n) cin >> a[i];
    int res = 0, prev = LLINF;
    FOR(i,0,n) {
        res += min(min(i+1, a[i]), prev+1);
        prev = min(min(i+1, a[i]), prev+1);
    }
    cout << res << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}