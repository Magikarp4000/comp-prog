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

const int MAXN = 3e5+5;
int n;
int a[MAXN], dp[MAXN];

void reset(int n) {
    FOR(i,0,n) {
        dp[i] = 1;
    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        cin >> n;
        reset(n);
        FOR(i,0,n) cin >> a[i];
        FOR(i,0,n) {
            FOR(j,max(0,i-513),i) {
                if ((a[j]^i) < (a[i]^j)) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int res = 0;
        FOR(i,0,n) res = max(res, dp[i]);
        cout << res << ln;
    }
}