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
#define int long long

const int MAXN = 2501;
int n;
vector<int> vx,vy;
UM<int,int> mx,my,mp,mp2;
bool g[MAXN][MAXN];
int p[MAXN][MAXN];
int c[MAXN];

signed main() {
  OPTM;
  cin >> n;
  FOR(i,0,n) {
    int x,y; cin >> x >> y;
    mp[x] = y; mp2[y] = x;
    vx.PB(x);
    vy.PB(y);
  }
  sort(ALL(vx));
  sort(ALL(vy));
  FOR(i,0,n) {
    mx[vx[i]] = i;
    my[vy[i]] = i;
  }
  FOR(i,0,n) c[i] = my[mp[vx[i]]];
  FOR(i,0,n) g[i][mx[mp2[vy[i]]]] = 1;
  FOR(i,1,n+1) {
    FOR(j,1,n+1) {
      p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+g[i-1][j-1];
    }
  }
  ll res = n+1;
  FOR(i,0,n-1) {
    FOR(j,i+1,n) {
      int x1 = i+1, y1 = min(c[i],c[j])+1, x2 = j+1, y2 = max(c[i],c[j])+1;
      int a = p[n][x2]-p[y2][x2]-p[n][x1-1]+p[y2][x1-1]+1;
      int b = p[y1-1][x2]-p[y1-1][x1-1]+1;
      res += a*b;
    }
  }
  cout << res;
}