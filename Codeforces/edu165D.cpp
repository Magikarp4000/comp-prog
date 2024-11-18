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
int n,k;
int a[MAXN], b[MAXN];

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        FOR(i,0,n) cin >> a[i];
        FOR(i,0,n) cin >> b[i];
        vector<PII> v;
        FOR(i,0,n) v.PB({b[i], a[i]});
        sort(ALL(v), greater<PII>());
        multiset<int> s;
        int lsum = 0, rsum = 0;
        FOR(i,0,k) lsum += v[i].S, s.insert(v[i].S);
        FOR(i,k,n) rsum += max(0LL, v[i].F-v[i].S);
        int res = max(0LL, rsum-lsum);
        FOR(i,k,n) {
            s.insert(v[i].S);
            lsum += v[i].S-(*(--s.end()));
            s.erase(--s.end());
            rsum -= max(0LL, v[i].F-v[i].S);
            res = max(res, rsum-lsum);
        }
        cout << res << ln;
    }
}