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

const int MAXN = 101;
int p[MAXN],q[MAXN];

int main() {
  freopen("milkorder.in", "r", stdin);
  freopen("milkorder.out", "w", stdout);
  OPTM;
  int n,m,k; cin >> n >> m >> k;
  int a[m];
  FOR(i,0,m) cin >> a[i];
  FOR(i,0,k) {
    int x,pos; cin >> x >> pos;
    p[pos] = x;
    q[x] = pos;
  }
  if (q[1]) {
    cout << q[1];
    return 0;
  }
  bool exists = 0;
  FOR(i,0,m) {
    if (a[i] == 1) {
      exists = 1;
      break;
    }
  }
  if (exists) {
    int cur = 1;
    FOR(i,0,m) {
      if (q[a[i]]) {
        cur = q[a[i]];
        continue;
      }
      while (p[cur] && cur <= n) cur++;
      p[cur] = a[i];
      q[a[i]] = cur;
      if (a[i] == 1) {
        cout << cur;
        return 0;
      }
    }
  }
  else {
    int cur = n;
    FORR(i,m-1,-1) {
      if (q[a[i]]) {
        cur = q[a[i]];
        continue;
      }
      while (p[cur] && cur >= 1) cur--;
      p[cur] = a[i];
      q[a[i]] = cur;
    }
    FOR(i,1,n+1) {
      if (!p[i]) {
        cout << i;
        return 0;
      }
    }
  }
}