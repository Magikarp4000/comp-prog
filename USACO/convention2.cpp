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
int n;
PII a[MAXN];
multiset<pair<int,pair<int,bool>>> s;
set<int> q;
int e[MAXN];
bool on = 0;

signed main() {
  freopen("convention2.in","r",stdin);
  freopen("convention2.out","w",stdout);
  OPTM;
  cin >> n;
  FOR(i,1,n+1) {
    cin >> a[i].F >> a[i].S;
    s.insert({a[i].F,{i,1}});
  }
  while (!s.empty()) {
    auto it = s.begin();
    auto tmp = *it;
    int x = tmp.F;
    int k = tmp.S.F;
    bool t = tmp.S.S;
    if (t == 1) {
      q.insert(k);
    }
    if (t == 0) {
      on = 0;
    }
    if (!on && !q.empty()) {
      int cur = *q.begin();
      q.erase(cur);
      e[cur] = x;
      s.insert({x+a[cur].S,{cur,0}});
      on = 1;
    }
    s.erase(it);
  }
  int res = 0;
  FOR(i,1,n+1) {
    res = max(res,e[i]-a[i].F);
  }
  cout << res;
}