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
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 1e5+1;
int T,n;
ll a[MAXN];

int main() {
  OPTM;
  cin >> T;
  while (T--) {
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    ll res = 0;
    if (n == 1) {
      cout << 0 << ln;
      continue;
    }
    else if (a[1]-a[0] < 0 || a[n-1]-a[n-2] > 0) {
      cout << -1 << ln;
      continue;
    }
    FORR(i,n-1,1) {
      ll diff = abs(a[i]-a[i-1]);
      if (a[i-1] > a[i]) {
        a[i-2] -= diff;
        a[i-1] -= diff;
        res += 2*diff;
      }
    }
    ll x = *min_element(a,a+n);
    FOR(i,0,n-1) {
      ll diff = abs(a[i]-x);
      if (a[i] > x) {
        a[i] -= diff;
        a[i+1] -= diff;
        res += 2*diff;
      }
    }
    bool ok = 1;
    FOR(i,0,n) {
      if (a[i] != a[0] || a[i] < 0) {
        ok = 0;
        cout << -1 << ln;
        break;
      }
    }
    if (ok) cout << res << ln;
  }
}