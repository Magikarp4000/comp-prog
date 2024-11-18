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

const int MAXN = 1e5+1, MAXK = 21;
int dp[MAXN][MAXK][3];
int a[MAXN];
UM<char,int> mp;
int p[3] = {1,2,0};
int sus[3][2] = {{1,2}, {0,2}, {0,1}};
int n,K;

signed main() {
  freopen("hps.in","r",stdin);
  freopen("hps.out","w",stdout);
  OPTM;
  mp['H'] = 0;
  mp['P'] = 1;
  mp['S'] = 2;
  cin >> n >> K;
  FOR(i,0,n) {
    char x; cin >> x;
    a[i] = mp[x];
  }
  FOR(i,0,3) dp[0][0][i] = i == p[a[0]] ? 1 : 0;
  FOR(i,1,n) {
    FOR(j,0,min(K,i)+1) {
      FOR(k,0,3) {
        int c = k == p[a[i]] ? 1 : 0;
        if (j > 0) dp[i][j][k] = max(dp[i-1][j][k], max(dp[i-1][j-1][sus[k][0]], dp[i-1][j-1][sus[k][1]]))+c;
        else dp[i][j][k] = dp[i-1][j][k]+c;
      }
    }
  }
  int res = -INF;
  FOR(j,0,K+1) FOR(k,0,3) res = max(res,dp[n-1][j][k]);
  cout << res;
}