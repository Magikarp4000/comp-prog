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

struct Rect {
  int ax,ay,bx,by;
};

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const int MAXN = 20;
char g[MAXN][MAXN];
int n;
bool z[MAXN][MAXN];
vector<Rect> pcl;

bool check(int ax, int ay, int bx, int by) {
  FOR(i,0,n) FOR(j,0,n) z[i][j] = 0;
  int cnt[26]; FOR(i,0,26) cnt[i] = 0;
  FOR(i,ay,by+1) {
    FOR(j,ax,bx+1) {
      if (!z[i][j]) {
        cnt[g[i][j]-'A']++;
        queue<PII> q; q.push({j,i});
        while (!q.empty()) {
          int x = q.front().F, y = q.front().S;
          q.pop();
          z[y][x] = 1;
          FOR(k,0,4) {
            int nx = x+dx[k], ny = y+dy[k];
            if (nx < ax || nx > bx || ny < ay || ny > by) continue;
            if (z[ny][nx]) continue;
            if (g[ny][nx] != g[y][x]) continue;
            q.push({nx,ny});
          }
        }
      }
    }
  }
  vector<int> good;
  FOR(i,0,26) {
    if (cnt[i] > 0) good.PB(cnt[i]);
  }
  if (good.size() != 2) return 0;
  sort(ALL(good));
  if (good[0] == 1 && good[1] > 1) return 1;
  return 0;
}

int main() {
  freopen("where.in", "r", stdin);
  freopen("where.out", "w", stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n) FOR(j,0,n) cin >> g[i][j];
  FOR(ay,0,n) {
    FOR(ax,0,n) {
      FOR(by,ay,n) {
        FOR(bx,ax,n) {
          if (check(ax,ay,bx,by)) pcl.PB({ax,ay,bx,by});
        }
      }
    }
  }
  int res = 0;
  int pn = pcl.size();
  FOR(i,0,pn) {
    bool ok = 1;
    FOR(j,0,pn) {
      if (j == i) continue;
      if (pcl[j].ax <= pcl[i].ax && pcl[j].bx >= pcl[i].bx && pcl[j].ay <= pcl[i].ay && pcl[j].by >= pcl[i].by) {
        ok = 0;
        break;
      }
    }
    if (ok) res++;
  }
  cout << res;
}