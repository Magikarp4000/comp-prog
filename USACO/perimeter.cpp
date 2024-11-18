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

const int MAXN = 1e3;
int n;
string g[MAXN];
bool z[MAXN][MAXN];
int area = 0, peri = 0;
int resa = 0, resp = 0;

void bfs(int sx, int sy) {
  queue<PII> q; q.push({sx,sy});
  while (!q.empty()) {
    int x = q.front().F, y = q.front().S;
    q.pop();
    if (x < 0 || x >= n || y < 0 || y >= n) {
      peri++;
      continue;
    }
    if (z[y][x]) continue;
    if (g[y][x] == '.') {
      peri++;
      continue;
    }
    z[y][x] = 1;
    area++;
    FOR(i,0,4) {
      q.push({x+dx[i],y+dy[i]});
    }
  }
}

int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n) cin >> g[i];
  FOR(i,0,n) {
    FOR(j,0,n) {
      if (!z[i][j]) {
        area = 0; peri = 0;
        bfs(j,i);
        if (area > resa || (area == resa && peri < resp)) {
          resa = area;
          resp = peri;
        }
      }
    }
  }
  cout << resa << ' ' << resp;
}