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

int main () {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  OPTM;
  int n; ll k;
  cin >> n >> k;
  ll a[n];
  FOR(i,0,n) {
    cin >> a[i];
  }
  sort(a,a+n);
  int l = 0, r = 0;
  int e[n];
  while (l <= n) {
    if (r == n) {
      e[l] = r;
      l++;
    }
    else if (a[r]-a[l] <= k) r++;
    else {
      e[l] = r;
      l++;
      if (r < l) r++;
    }
  }
  int dp[n+1]; dp[n] = 0;
  FORR(i,n-1,-1) {
    dp[i] = max(dp[i+1],e[i]-i);
  }
  int res = 0;
  FOR(i,0,n) {
    if (e[i] < n) res = max(res,e[i]-i+dp[e[i]]);
    else res = max(res,e[i]-i);
  }
  cout << res;
}