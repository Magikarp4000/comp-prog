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

const int MAXN = 1e5+1;
int n;
int a[MAXN];

signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,0,n) {
            cin >> a[i];
            a[i] += INF;
        }
        int val = 0, ma = a[0];
        FOR(i,1,n) {
            val = max(val,ma-a[i]);
            ma = max(ma,a[i]);
        }
        int rizz = 0;
        FORR(j,31,-1) {
            if (val&(1<<(j*1LL))) {
                rizz = j+1;
                break;
            }
        }
        cout << rizz << ln;
    }
}