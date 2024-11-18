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
#define int long long

const int MAXN = 41;
int n,x;
int a[MAXN];
vector<int> v;

signed main() {
    cin >> n >> x;
    FOR(i,0,n) cin >> a[i];
    int h = n%2 == 0 ? n/2 : n/2+1;
    FOR(s,0,1<<h) {
        int sum = 0;
        FOR(j,0,h) {
            if (s&(1<<j)) {
                sum += a[n/2+j];
            }
        }
        v.PB(sum);
    }
    sort(ALL(v));
    int res = 0;
    FOR(s,0,1<<(n/2)) {
        int sum = 0;
        FOR(j,0,n/2) {
            if (s&(1<<j)) {
                sum += a[j];
            }
        }
        auto it = upper_bound(ALL(v),x-sum);
        auto it1 = lower_bound(ALL(v),x-sum);
        int cur = max(0ll,1LL*(it-it1));
        res += cur;
    }
    cout << res;
}