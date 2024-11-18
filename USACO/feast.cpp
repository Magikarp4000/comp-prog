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

const int MAXN = 5e6+1;
int T,A,B;
bool dp[MAXN],dp1[MAXN];

signed main() {
  freopen("feast.in","r",stdin);
  freopen("feast.out","w",stdout);
  OPTM;
  cin >> T >> A >> B;
  dp[0] = 1; dp1[0] = 1;
  FOR(i,1,T+1) {
    if (i-A >= 0 && dp[i-A]) dp[i] = 1;
    if (i-B >= 0 && dp[i-B]) dp[i] = 1;
    if (dp[i]) dp1[i/2] = 1;
  }
  FOR(i,1,T+1) {
    if (i-A >= 0 && dp1[i-A]) dp1[i] = 1;
    if (i-B >= 0 && dp1[i-B]) dp1[i] = 1;
  }
  FORR(i,T,0) {
    if (dp[i] || dp1[i]) {
      cout << i;
      break;
    }
  }
}