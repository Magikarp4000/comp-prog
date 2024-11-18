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

const int MAXN = 1e3;
int n;
pair<ll,ll> a[MAXN];
vector<int> v[MAXN];
bool z[MAXN];

void dfs(int s) {
  if (z[s]) return;
  z[s] = 1;
  FORX(u,v[s]) dfs(u);
}

bool check(ll x) {
  FOR(i,0,n) v[i].clear();
  FOR(i,0,n) {
    FOR(j,0,n) {
      if (j == i) continue;
      if ((a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S) <= x) {
        v[i].PB(j);
      }
    }
  }
  FOR(i,0,n) z[i] = 0;
  dfs(0);
  FOR(i,0,n) if (!z[i]) return 0;
  return 1;
}

ll bsearch() {
  ll l = 1, r = 1.5e9;
  while (l < r) {
    ll mid = r+(l-r)/2;
    if (check(mid)) {
      if (!check(mid-1)) return mid;
      else r = mid-1;
    }
    else {
      if (check(mid+1)) return mid+1;
      else l = mid;
    }
  }
  return l;
}

int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n) {
    cin >> a[i].F >> a[i].S;
  }
  cout << bsearch();
}