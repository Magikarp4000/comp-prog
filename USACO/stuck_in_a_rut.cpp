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

const int MAXN = 51;
int n;
pair<char,PII> a[MAXN];
vector<pair<int,PII>> v;
int d[MAXN];

int main() {
  OPTM;
  cin >> n;
  FOR(i,0,n) cin >> a[i].F >> a[i].S.F >> a[i].S.S;
  FOR(i,0,n) {
    FOR(j,0,n) {
      if (a[i].F == a[j].F) continue;
      int ax = a[i].S.F, ay = a[i].S.S;
      int bx = a[j].S.F, by = a[j].S.S;
      if (a[i].F == 'E') {
        if (bx > ax && by < ay) {
          if (ay-by < bx-ax) v.PB({bx-ax,{i,j}});
        }
      }
      else {
        if (bx < ax && by > ay) {
          if (ax-bx < by-ay) v.PB({by-ay,{i,j}});
        }
      }
    }
  }
  sort(ALL(v));
  FOR(i,0,n) d[i] = INF;
  FORX(u,v) {
    int p = u.S.F, q = u.S.S;
    if (a[p].F == 'E') {
      if (d[q] >= a[p].S.S) d[p] = min(d[p], a[q].S.F-1);
    }
    else {
      if (d[q] >= a[p].S.F) d[p] = min(d[p], a[q].S.S-1);
    }
  }
  FOR(i,0,n) {
    if (d[i] == INF) cout << "Infinity";
    else if (a[i].F == 'E') cout << d[i]-a[i].S.F+1;
    else cout << d[i]-a[i].S.S+1;
    cout << ln;
  }
}