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

const ll MAXX = 1e18;
int n,m;
vector<pair<ll,ll>> v;

bool check(ll d) {
  ll j = 0, x = v[0].F;
  FOR(i,0,n-1) {
    while (j < m && v[j].S-x < d) j++;
    if (j == m) return 0;
    x = max(v[j].F, x+d);
  }
  return 1;
}

int main() {
  freopen("socdist.in", "r", stdin);
  freopen("socdist.out", "w", stdout);
  OPTM;
  cin >> n >> m;
  FOR(i,0,m) {
    ll a,b; cin >> a >> b;
    v.PB({a,b});
  }
  sort(ALL(v));
  ll l = 1, r = MAXX;
  while (l < r) {
    ll mid = (l+r+1)/2;
    if (check(mid)) {
      l = mid;
    }
    else {
      r = mid-1;
    }
  }
  cout << l;
}