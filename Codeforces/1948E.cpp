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

const int MAXN = 41;
int n,k;
int a[MAXN], c[MAXN];

void solve() {
    cin >> n >> k;
    int m = (n+k-1)/k;
    FOR(idx,0,m) {
        int base = idx*k, cur = min(n-base,k)/2;
        FOR(i,base,min(n,base+k)) {
            if (cur == 0) cur = min(n-base,k);
            a[i] = base+cur;
            c[i] = idx+1;
            cur--;
        }
    }
    FOR(i,0,n) cout << a[i] << " ";
    cout << ln << m << ln;
    FOR(i,0,n) cout << c[i] << " ";
    cout << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}