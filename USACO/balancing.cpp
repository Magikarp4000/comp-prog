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
const ll LLINF = 1e18+1;

int n,k;

int main() {
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);
  OPTM;
  cin >> n >> k;
  PII a[n];
  US<int> r,c;
  FOR(i,0,n) {
    int x,y; cin >> x >> y;
    a[i] = {x,y};
    r.insert(y+1);
    r.insert(y-1);
    c.insert(x+1);
    c.insert(x-1);
  }
  int res = INF;
  FORX(u,r) {
    FORX(v,c) {
      int tl=0,tr=0,bl=0,br=0;
      FOR(i,0,n) {
        int x = a[i].F, y = a[i].S;
        if (x < v && y < u) bl++;
        else if (x < v && y > u) br++;
        else if (x > v && y < u) tl++;
        else if (x > v && y > u) tr++;
      }
      int cur = max(max(tl,tr),max(bl,br));
      res = min(res,cur);
    }
  }
  cout << res;
}