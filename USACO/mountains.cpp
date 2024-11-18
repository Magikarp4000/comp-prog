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
const ll LLINF = 5e18+1;

struct Point {
  int x,y;
};

bool cmp(const Point& a, const Point& b) {
  if (a.x-a.y != b.x-b.y) return a.x-a.y < b.x-b.y;
  return a.y > b.y;
}


int main() {
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);
  OPTM;
  int n; cin >> n;
  Point a[n]; FOR(i,0,n) cin >> a[i].x >> a[i].y;
  sort(a,a+n,cmp);
  int ma = -INF;
  int obs = 0;
  FOR(i,0,n) {
    if (a[i].x+a[i].y <= ma) obs++;
    ma = max(ma,a[i].x+a[i].y);
  }
  cout << n-obs;
}