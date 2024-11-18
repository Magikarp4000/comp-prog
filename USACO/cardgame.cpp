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

int main() {
  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);
  OPTM;
  int n; cin >> n;
  US<int> cards;
  set<int> h,l;
  FOR(i,0,n/2) {
    int x; cin >> x;
    h.insert(x);
    cards.insert(x);
  }
  FOR(i,0,n/2) {
    int x; cin >> x;
    l.insert(x);
    cards.insert(x);
  }
  vector<int> v;
  FOR(i,1,2*n+1) if (!cards.count(i)) v.PB(i);
  sort(ALL(v));
  int res = 0;
  FORR(i,n/2-1,-1) {
    if (v[i] > *l.rbegin()) continue;
    l.erase(*l.upper_bound(v[i]));
    res++;
  }
  FOR(i,n/2,n) {
    if (v[i] < *h.begin()) continue;
    auto it = h.lower_bound(v[i]);
    it--;
    h.erase(*it);
    res++;
  }
  cout << res;
}