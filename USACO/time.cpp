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

const int MAXN = 1e3+1, MAXD = 1e3+1;
vector<int> v[MAXN];
int n,m,c;
int dp[MAXD][MAXN];
int w[MAXN];

signed main() {
  freopen("time.in","r",stdin);
  freopen("time.out","w",stdout);
  OPTM;
  cin >> n >> m >> c;
  FOR(i,1,n+1) cin >> w[i];
  FOR(i,0,m) {
    int a,b; cin >> a >> b;
    v[a].PB(b);
  }
  dp[0][1] = 0;
  US<int> cur;
  cur.insert(1);
  FOR(i,1,MAXD) {
    US<int> tmp;
    FORX(s,cur) {
      FORX(u,v[s]) {
        dp[i][u] = max(dp[i][u], dp[i-1][s]+w[u]);
        tmp.insert(u);
      }
    }
    cur.clear();
    FORX(u,tmp) cur.insert(u);
  }
  int res = 0;
  FOR(i,0,MAXD) res = max(res,dp[i][1]-c*i*i);
  cout << res;
}