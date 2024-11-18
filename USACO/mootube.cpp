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

const int MAXN = 5e3+1;
vector<PII> v[MAXN];
int dp[MAXN];

void dfs(int s, int pa) {
  FORX(u,v[s]) {
    if (u.F == pa) continue;
    dp[u.F] = min(u.S,dp[s]);
    dfs(u.F,s);
  }
}

int main() {
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);
  OPTM;
  int n,q; cin >> n >> q;
  FOR(i,0,n-1) {
    int a,b,w; cin >> a >> b >> w;
    v[a].PB({b,w});
    v[b].PB({a,w});
  }
  while (q--) {
    int s,k; cin >> k >> s;
    dp[s] = INF;
    dfs(s,-1);
    int res = 0;
    FOR(i,1,n+1) if (dp[i] >= k) res++;
    res--;
    cout << res << ln;
  }
}