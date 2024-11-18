#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+7)
#define ln '\n' 
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,n,s) for (int i = n; i > s; i--)
#define FORX(u, arr) for (auto u : arr)
#define PB push_back
#define in(v,x) (v.find(x) != v.end())
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

const int MAXN = 5e5+1, LOG = 62;
int n;
int a[MAXN], cnt[MAXN], lg[MAXN];

signed main() {
    int t; cin >> t;
    lg[0] = 1LL;
    FOR(j,1,LOG) lg[j] = (lg[j-1]<<1LL)%INF;
    while (t--) {
        cin >> n;
        FOR(i,0,n) cin >> a[i];
        FOR(j,0,LOG) cnt[j] = 0LL;
        FOR(j,0,LOG) {
            FOR(i,0,n) cnt[j] += (a[i]&(1LL<<j)) ? 1LL : 0LL;
        }
        int res = 0LL;
        FOR(i,0,n) {
            int x = 0LL, y = 0LL;
            FOR(j,0,LOG) {
                if (a[i]&(1LL<<j)) {
                    x = (x+(lg[j]*n)%INF)%INF;
                    y = (y+(lg[j]*cnt[j])%INF)%INF;
                }
                else x = (x+(lg[j]*cnt[j])%INF)%INF;
            }
            res = (res+(x*y)%INF)%INF;
        }
        cout << res << ln;
    }
}