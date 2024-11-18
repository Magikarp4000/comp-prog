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

map<ll,pair<ll,ll>> mx,my;

struct Coord {
  ll a,bmin,bmax;
};

int main() {
  freopen("split.in", "r", stdin);
  freopen("split.out", "w", stdout);
  OPTM;
  
  // Get input
  int n; cin >> n;
  ll xmin = INF, xmax = -INF, ymin = INF, ymax = -INF;
  FOR(i,0,n) {
    ll x,y; cin >> x >> y;
    xmin = min(xmin,x);
    xmax = max(xmax,x);
    ymin = min(ymin,y);
    ymax = max(ymax,y);
    if (!mx.count(x)) mx[x] = {y,y};
    else {
      mx[x].F = min(mx[x].F,y);
      mx[x].S = max(mx[x].S,y);
    }
    if (!my.count(y)) my[y] = {x,x};
    else {
      my[y].F = min(my[y].F,x);
      my[y].S = max(my[y].S,x);
    }
  }
  vector<Coord> vx,vy;
  FORX(u,mx) vx.PB({u.F,u.S.F,u.S.S});
  FORX(u,my) vy.PB({u.F,u.S.F,u.S.S});
  int xn = vx.size(), yn = vy.size();
  
  // Precomputation
  pair<ll,ll> y1[xn+1], y2[xn+1], x1[yn+1], x2[yn+1];
  y1[0] = {INF,-INF}; y2[xn] = {INF,-INF};
  x1[0] = {INF,-INF}; x2[yn] = {INF,-INF};
  FOR(i,1,xn+1) {
    y1[i].F = min(y1[i-1].F,vx[i-1].bmin);
    y1[i].S = max(y1[i-1].S,vx[i-1].bmax);
  }
  FORR(i,xn-1,-1) {
    y2[i].F = min(y2[i+1].F,vx[i].bmin);
    y2[i].S = max(y2[i+1].S,vx[i].bmax);
  }
  FOR(i,1,yn+1) {
    x1[i].F = min(x1[i-1].F,vy[i-1].bmin);
    x1[i].S = max(x1[i-1].S,vy[i-1].bmax);
  }
  FORR(i,yn-1,-1) {
    x2[i].F = min(x2[i+1].F,vy[i].bmin);
    x2[i].S = max(x2[i+1].S,vy[i].bmax);
  }
  
  // Solving
  ll res = LLINF;
  FOR(i,0,xn-1) {
    ll cur = (y1[i+1].S-y1[i+1].F)*(vx[i].a-vx[0].a) + (y2[i+1].S-y2[i+1].F)*(vx[xn-1].a-vx[i+1].a);
    res = min(res,cur);
  }
  FOR(i,0,yn-1) {
    ll cur = (x1[i+1].S-x1[i+1].F)*(vy[i].a-vy[0].a) + (x2[i+1].S-x2[i+1].F)*(vy[yn-1].a-vy[i+1].a);
    res = min(res,cur);
  }
  ll total = (ymax-ymin)*(xmax-xmin);
  cout << total-res;
}