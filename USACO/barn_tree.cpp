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

const int MAXN = 2e5+1;
int n;
vector<int> v[MAXN];
ll a[MAXN], dp[MAXN];
ll avg;
vector<pair<PII,ll>> sq;

void dfs(int s, int pa) {
  dp[s] += avg-a[s];
  //FOR(i,1,n+1) cout << dp[i] << ' ';
  FORX(u,v[s]) {
    if (u == pa) continue;
    dfs(u,s);
    dp[s] += dp[u];
    //if (s == 2) cout << dp[s] << ln;
    if (dp[u] < 0) {
      sq.PB({{u,s},abs(dp[u])});
      a[u] -= abs(dp[u]);
      
      a[s] += abs(dp[u]);
      dp[u] = 0;
    }
  }
}

void dfs1(int s, int pa) {
  FORX(u,v[s]) {
    if (u == pa) continue;
    if (dp[u] > 0) {
      sq.PB({{s,u},abs(dp[u])});
      a[s] -= abs(dp[u]);
      a[u] += abs(dp[u]);
      dp[u] = 0;
    }
    dfs1(u,s);
  }
}

int main() {
  //freopen("berries.in","r",stdin);
  //freopen("berries.out","w",stdout);
  OPTM;
  cin >> n;
  ll sum = 0;
  FOR(i,1,n+1) {
    cin >> a[i];
    sum += a[i];
  }
  avg = sum/n;
  FOR(i,0,n-1) {
    int x,y; cin >> x >> y;
    v[x].PB(y);
    v[y].PB(x);
  }
  dfs(1,-1);
  //FOR(i,1,n+1) cout << dp[i] << ' ';
  dfs1(1,-1);
  cout << sq.size() << ln;
  FORX(u,sq) cout << u.F.F << ' ' << u.F.S << ' ' << u.S << ln;
}