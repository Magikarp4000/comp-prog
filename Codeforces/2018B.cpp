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

const int MAXN = 2e5+5;
int n;
int a[MAXN], pl[MAXN], pr[MAXN];

void reset() {
    FOR(i,0,n+2) {
        pl[i] = INF;
        pr[i] = -INF;
    }
}

int solve() {
    cin >> n;
    reset();
    FOR(i,1,n+1) cin >> a[i];
    FOR(i,1,n+1) pl[i] = min(pl[i-1], min(n, i+a[i]-1));
    FORR(i,n,0) pr[i] = max(pr[i+1], max(1, i-a[i]+1));
    FOR(i,1,n+1) {
        if (i-a[i] >= 1 && pl[i-a[i]] < i) return 0;
        if (i+a[i] <= n && pr[i+a[i]] > i) return 0;
    }
    int res = 0;
    FOR(i,1,n+1) {
        if (pl[i-1] < i || pr[i+1] > i) continue;
        res++;
    }
    return res;
}

signed main() {         
    OPTM;
    int T; cin >> T;
    while (T--) cout << solve() << ln;
}