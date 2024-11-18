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

const int MAXN = 4e2+1;
int n,k;
int a[MAXN][MAXN], p[MAXN][MAXN];
int res = 0;

int main() {
  freopen("lazy.in","r",stdin);
  freopen("lazy.out","w",stdout);
  OPTM;
  cin >> n >> k;
  FOR(i,0,n) FOR(j,0,n) cin >> a[i][j];
  FOR(i,0,n) FOR(j,0,n) p[i][j+1] = p[i][j]+a[i][j];
  FOR(i,0,n) {
    FOR(j,0,n) {
      int cur = 0;
      int l = 1;
      while (l <= k && i-l >= 0) {
        cur += p[i-l][min(n,j+k-l+1)]-p[i-l][max(0,j-(k-l))];
        l++;
      }
      l = 1;
      while (l <= k && i+l < n) {
        cur += p[i+l][min(n,j+k-l+1)]-p[i+l][max(0,j-(k-l))];
        l++;
      }
      cur += p[i][min(n,j+k+1)]-p[i][max(0,j-k)];
      res = max(res,cur);
    }
  }
  cout << res;
}