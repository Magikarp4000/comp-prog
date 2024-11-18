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

const int MAXN = 3e5+5;
int a[MAXN];

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        int n,c; cin >> n >> c;
        FOR(i,0,n) cin >> a[i];
        int res = (c+1ll)*(c+2ll)/2ll;
        FOR(i,0,n) res -= (a[i]/2ll+1ll) + (c-a[i]+1ll);
        int e = 0, o = 0;
        FOR(i,0,n) {
            if (a[i]%2ll) o++;
            else e++;
        }
        res += e*(e+1ll)/2ll + o*(o+1ll)/2ll;
        cout << res << ln;
    }
}