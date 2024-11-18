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

const int MAXN = 1e3+1;
int h,g;
pair<ll,ll> a[MAXN], b[MAXN];
ll dp[MAXN][MAXN][2];

int sq(pair<ll,ll> x, pair<ll,ll> y) {
  return abs(x.F-y.F)*abs(x.F-y.F)+abs(x.S-y.S)*abs(x.S-y.S);
}

int main() {
  freopen("checklist.in","r",stdin);
  freopen("checklist.out","w",stdout);
  OPTM;
  cin >> h >> g;
  FOR(i,0,h) cin >> a[i].F >> a[i].S;
  FOR(i,0,g) cin >> b[i].F >> b[i].S;
  FOR(i,0,h+1) FOR(j,0,g+1) FOR(k,0,2) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  dp[0][1][1] = sq(a[0],b[0]);
  FOR(j,2,g+1) dp[0][j][1] = dp[0][j-1][1]+sq(b[j-2],b[j-1]);
  FOR(i,1,h-1) dp[i][0][0] = dp[i-1][0][0]+sq(a[i-1],a[i]);
  FOR(i,1,h-1) {
    FOR(j,1,g+1) {
      dp[i][j][0] = min(dp[i-1][j][0]+sq(a[i-1],a[i]), dp[i-1][j][1]+sq(b[j-1],a[i]));
      dp[i][j][1] = min(dp[i][j-1][0]+sq(a[i],b[j-1]), dp[i][j-1][1]+sq(b[j-2],b[j-1]));
    }
  }
  cout << min(dp[h-2][g][0]+sq(a[h-2],a[h-1]), dp[h-2][g][1]+sq(b[g-1],a[h-1]));
}