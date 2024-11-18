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
const ll LLINF = 1e18+1;

int speed[100];

int main() {
  OPTM;
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);
  int K,n; cin >> K >> n;
  int a[K][n];
  FOR(i,0,K) FOR(j,0,n) cin >> a[i][j];
  int res = 0;
  FOR(i,1,n) {
    FOR(j,i+1,n+1) {
      bool ii = 0, jj = 0;
      FOR(k,0,K) {
        int ipos,jpos;
        FOR(l,0,n) {
          if (a[k][l] == i) ipos = l;
          if (a[k][l] == j) jpos = l;
        }
        if (ipos < jpos) ii = 1;
        else if (ipos > jpos) jj = 1;
      }
      if (!(ii && jj)) res++;
    }
  }
  cout << res;
}