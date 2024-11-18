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

const int MAXN = 1e5;
int n,sum;
int a[MAXN];

bool check(int x) {
  int cur = 0;
  FOR(i,0,n) {
    cur += a[i];
    if (cur == sum/x) cur = 0;
    else if (cur > sum/x) return 0;
  }
  return 1;
}

int main() {
  //freopen("balancing.in", "r", stdin);
  //freopen("balancing.out", "w", stdout);
  OPTM;
  int T; cin >> T;
  while (T--) {
    cin >> n;
    sum = 0;
    FOR(i,0,n) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum == 0) cout << 0 << ln;
    FORR(i,sum,0) {
      if (sum%i == 0) {
        if (check(i)) {
          cout << n-i << ln;
          break;
        }
      }
    }
  }
}