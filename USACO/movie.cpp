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

const int MAXN = 20;
int n,l;
int d[MAXN];
set<int> a[MAXN];
int dp[(1<<MAXN)+1];

signed main() {
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);
    OPTM;
    cin >> n >> l;
    FOR(i,0,n) {
        cin >> d[i];
        int c; cin >> c;
        FOR(j,0,c) {
            int x; cin >> x;
            a[i].insert(x);
        }
    }
    FOR(s,0,1<<n) {
        FOR(j,0,n) {
            if (s&(1<<j)) {
                if (dp[s^(1<<j)] < *a[j].begin()-1) continue;
                auto it = a[j].upper_bound(dp[s^(1<<j)]);
                it--;
                dp[s] = max(dp[s], max(dp[s^(1<<j)], (*it)+d[j]));
            }
        }
    }
    int res = INF;
    FOR(s,0,1<<n) {
        if (dp[s] >= l) {
            res = min(res, __builtin_popcount(s));
        }
    }
    if (res == INF) cout << -1;
    else cout << res;
}