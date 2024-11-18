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

const int MAXN = 401;
int n,K;
int a[MAXN], dp[MAXN][MAXN];

signed main() {
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  OPTM;
  cin >> n >> K;
  FOR(i,0,n) cin >> a[i];
  int sum = 0;
  FOR(i,0,n) sum += a[i];
  FOR(i,0,n) FOR(j,0,K+1) dp[i][j] = INF;
  int maxx = -INF;
  FOR(i,0,n) {
    maxx = max(maxx,a[i]);
    dp[i][0] = maxx*(i+1);
    FOR(j,1,min(K,i)+1) {
      int cur = -INF;
      FORR(k,i,j-1) {
        cur = max(cur,a[k]);
        dp[i][j] = min(dp[i][j], dp[k-1][j-1]+cur*(i-k+1));
      }
    }
  }
  int res = INF;
  FOR(j,0,K+1) res = min(res,dp[n-1][j]);
  cout << res-sum;
}