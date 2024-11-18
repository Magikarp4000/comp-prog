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

const int MAXN = 1e3+2;
int n,k;
int e[MAXN][MAXN], p[MAXN][MAXN];

int main() {
  freopen("paintbarn.in","r",stdin);
  freopen("paintbarn.out","w",stdout);
  OPTM;
  cin >> n >> k;
  FOR(i,0,n) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    c--; d--;
    e[b][a]++;
    e[b][c+1]--;
    e[d+1][a]--;
    e[d+1][c+1]++;
  }
  p[0][0] = e[0][0];
  FOR(i,0,MAXN) p[i][0] = p[i-1][0]+e[i][0];
  FOR(j,0,MAXN) p[0][j] = p[0][j-1]+e[0][j];
  FOR(i,1,MAXN) {
    FOR(j,1,MAXN) {
      p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+e[i][j];
    }
  }
  int res = 0;
  FOR(i,0,MAXN-1) {
    FOR(j,0,MAXN-1) {
      if (p[i][j] == k) res++;
    }
  }
  cout << res;
}