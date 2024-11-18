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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const int MAXN = 501;
int n,m;
int g[MAXN][MAXN];
bool z[MAXN][MAXN], w[MAXN][MAXN];
PII start = {-1,-1};

bool check(int d) {
  FOR(i,0,n) FOR(j,0,m) z[i][j] = 0;
  queue<PII> q; q.push(start);
  z[start.S][start.F] = 1;
  while (!q.empty()) {
    int x = q.front().F, y = q.front().S;
    q.pop();
    FOR(i,0,4) {
      int nx = x+dx[i], ny = y+dy[i];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
        if (!z[ny][nx] && abs(g[y][x]-g[ny][nx]) <= d) {
          q.push({nx,ny});
          z[ny][nx] = 1;
        }
      }
    }
  }
  FOR(i,0,n) {
    FOR(j,0,m) {
      if (w[i][j] && !z[i][j]) return 0;
    }
  }
  return 1;
}

int bsearch() {
  int l = 0, r = 1000000000;
  while (l < r) {
    int mid = (l+r)/2;
    if (check(mid)) {
      //if (!check(mid-1)) return mid;
      r = mid;
    }
    else {
      //if (check(mid+1)) return mid+1;
      l = mid+1;
    }
  }
  return l;
}

int main() {
  freopen("ccski.in", "r", stdin);
  freopen("ccski.out", "w", stdout);
  OPTM;
  cin >> n >> m;
  FOR(i,0,n) FOR(j,0,m) cin >> g[i][j];
  FOR(i,0,n) {
    FOR(j,0,m) {
      cin >> w[i][j];
      if (w[i][j] == 1) start = {j,i};
    }
  }
  cout << bsearch();
}