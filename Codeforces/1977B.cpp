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

const int MAXN = 32;
int x;
int a[MAXN];

void solve() {
    cin >> x;
    FOR(i,0,32) a[i] = 0;
    a[0] = (x&1);
    FOR(j,1,32) {
        if (!(x&(1<<j))) continue;
        if (a[j]) a[j] = 0, a[j+1] = 1;
        else if (a[j-1]) a[j-1] = -1, a[j+1] = 1;
        else a[j] = 1;
    }
    cout << 32 << ln;
    FOR(i,0,32) cout << a[i] << " ";
    cout << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}