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

const int MAXN = 200;
vector<int> v[MAXN];
bool z[MAXN];

void dfs(int s) {
  if (z[s]) return;
  z[s] = 1;
  FORX(u,v[s]) dfs(u);
}

int main () {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  OPTM;
  int n; cin >> n;
  pair<pair<ll,ll>,ll> a[n];
  FOR(i,0,n) {
    cin >> a[i].F.F >> a[i].F.S >> a[i].S;
  }
  FOR(i,0,n) {
    FOR(j,0,n) {
      if (j == i) continue;
      if ((a[j].F.F-a[i].F.F)*(a[j].F.F-a[i].F.F) + (a[j].F.S-a[i].F.S)*(a[j].F.S-a[i].F.S) <= a[i].S*a[i].S) {
        v[i].PB(j);
      }
    }
  }
  int res = 0, cur = 0;
  FOR(i,0,n) {
    cur = 0;
    FOR(j,0,n) z[j] = 0;
    dfs(i);
    FOR(j,0,n) cur += z[j];
    res = max(res,cur);
  }
  cout << res;
}