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
int a[MAXN];

int solve() {
    int n; cin >> n;
    FOR(i,0,n) cin >> a[i];
    int res = 0, prev = 0;
    FOR(i,1,n) {
        if (a[i] == 1 && a[i-1] != 1) return -1;
        int cnt = 0;
        if (a[i-1] != 1) {
            int sm = min(a[i], a[i-1]), la = max(a[i], a[i-1]);
            while (sm < la) sm *= sm, cnt++;
            if (a[i] > a[i-1]) {
                cnt *= -1;
                if (sm != la) cnt++;
            }
        }
        prev = max(0ll, prev+cnt);
        res += prev;
    }
    return res;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << solve() << ln;
}