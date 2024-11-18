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

const int MAXN = 5e2+1;
int n;
int a[MAXN][MAXN];
vector<int> v[MAXN];
bool z[MAXN], w[MAXN][MAXN];

void dfs(int s, int k) {
  if (z[s]) return;
  z[s] = 1;
  w[k][s] = 1;
  FORX(u,v[s]) dfs(u,k);
}

int main() {
  OPTM;
  cin >> n;
  FOR(i,1,n+1) FOR(j,0,n) cin >> a[i][j];
  FOR(i,1,n+1) {
    FOR(j,0,n) {
      v[i].PB(a[i][j]);
      if (a[i][j] == i) break;
    }
  }
  FOR(i,1,n+1) {
    FOR(j,1,n+1) z[j] = 0;
    dfs(i,i);
  }
  FOR(i,1,n+1) {
    FOR(j,0,n) {
      if (w[i][a[i][j]] && w[a[i][j]][i]) {
        cout << a[i][j] << ln;
        break;
      }
    }
  }
}