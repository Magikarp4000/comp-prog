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
int n,m;
int a[MAXN], b[MAXN], v[MAXN], p[MAXN], t[MAXN];

void solve() {
    cin >> n >> m;
    FOR(i,0,n+m+1) cin >> a[i];
    FOR(i,0,n+m+1) cin >> b[i];
    int pcnt = 0, tcnt = 0, px = 0, tx = 0;
    FOR(i,0,n+m+1) {
        if (pcnt == n && a[i] > b[i]) px = i;
        if (tcnt == n && a[i] < b[i]) tx = i;
        if (pcnt >= n || a[i] < b[i]) v[i] = b[i], tcnt++;
        else if (tcnt >= m) v[i] = a[i], pcnt++;
        else if (a[i] > b[i]) v[i] = a[i], pcnt++;
        else v[i] = b[i], tcnt++;
    }
    FOR(i,0,n+m+1) {

    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}