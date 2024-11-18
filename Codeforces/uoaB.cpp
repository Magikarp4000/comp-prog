#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int(1e9+7)
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,s,n) for (int i = s; i > n; i--)
#define ln '\n'
#define int long long
const long long LLINF = 1e18;

const int MAXN = 5e3+5;
int a[MAXN];

void solve() {
    int n; cin >> n;
    FOR(i,0,n) cin >> a[i];
    int res = LLINF;
    FOR(i,0,n) {
        int cnt = 0, cur = 0;
        FORR(j,i-1,-1) {
            int x = cur/a[j]+1;
            cnt += x, cur = a[j]*x;
        }
        cur = 0;
        FOR(j,i+1,n) {
            int x = cur/a[j]+1;
            cnt += x, cur = a[j]*x;
        }
        res = min(res, cnt);
    }
    cout << res << ln;
}

signed main() {
    OPTM;
    solve();
}