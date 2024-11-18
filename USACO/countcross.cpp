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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
const int MAXN = 1e2;
int n,k,r;
UM<int,US<int>> a[MAXN][MAXN];
vector<PII> v;
bool z[MAXN][MAXN], z1[MAXN][MAXN];
vector<int> t;

int main() {
  freopen("countcross.in", "r", stdin);
  freopen("countcross.out", "w", stdout);
  OPTM;
  cin >> n >> k >> r;
  FOR(i,0,r) {
    int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    a[r1][c1][c2].insert(r2);
    a[r2][c2][c1].insert(r1);
  }
  FOR(i,0,k) {
    int x,y; cin >> y >> x;
    x--; y--;
    v.PB({x,y});
  }
  int res = 0;
  FOR(i,0,k) {
    if (!z[v[i].S][v[i].F]) {
      FOR(j,0,n) FOR(l,0,n) z1[j][l] = 0;
      queue<PII> q; q.push(v[i]);
      while (!q.empty()) {
        int x = q.front().F, y = q.front().S;
        q.pop();
        //cout << x << ' ' << y << ln;
        z[y][x] = 1;
        z1[y][x] = 1;
        FOR(l,0,4) {
          int nx = x+dx[l], ny = y+dy[l];
          if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!z[ny][nx] && !a[y][x][nx].count(ny)) {
              z[ny][nx] = 1;
              q.push({nx,ny});
            }
          }
        }
      }
      int cur = 0;
      FOR(j,0,k) {
        if (z1[v[j].S][v[j].F]) cur++;
      }
      t.PB(cur);
    }
    /*FOR(j,0,n) {
      FOR(l,0,n) cout << z[j][l] << ' ';
      cout << ln;
    }
    cout << ln;*/
  }
  int sum = 0;
  FOR(i,0,(int)t.size()) sum += t[i];
  FOR(i,0,(int)t.size()) {
    sum -= t[i];
    res += t[i]*sum;
  }
  cout << res;
}