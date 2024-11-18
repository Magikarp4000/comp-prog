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
int n,m;
pair<ll,ll> a[MAXN];
vector<int> v[MAXN];
bool z[MAXN];
vector<vector<int>> comps;

void dfs(int s, int k) {
  if (z[s]) return;
  z[s] = 1;
  comps[k].PB(s);
  FORX(u,v[s]) dfs(u,k);
}

int main() {
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
  OPTM;
  cin >> n >> m;
  FOR(i,1,n+1) {
    cin >> a[i].F >> a[i].S;
  }
  FOR(i,0,m) {
    int p,q; cin >> p >> q;
    v[p].PB(q);
    v[q].PB(p);
  }
  int cur = 0;
  FOR(i,1,n+1) {
    if (!z[i]) {
      vector<int> tmp;
      comps.PB(tmp);
      dfs(i,cur);
      cur++;
    }
  }
  ll res = LLINF;
  FORX(comp,comps) {
    ll ymi = INF, yma = -INF, xmi = INF, xma = -INF;
    FORX(u,comp) {
      ymi = min(ymi,a[u].S);
      yma = max(yma,a[u].S);
      xmi = min(xmi,a[u].F);
      xma = max(xma,a[u].F);
    }
    res = min(res,2*(yma-ymi)+2*(xma-xmi));
  }
  cout << res;
}