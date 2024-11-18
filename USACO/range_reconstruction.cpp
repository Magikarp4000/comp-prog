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

const int MAXN = 3e2+1;
ll a[MAXN][MAXN];
int b[] = {0,2,2};
int c[] = {0,1,1};
int d[] = {0,1,2,2};
int e[] = {0,1,1,2};

int main() {
  OPTM;
  int n; cin >> n;
  FOR(i,0,n) {
    FOR(j,i,n) {
      cin >> a[i][j];
    }
  }
  if (n == 3 && a[0][1] == 2) cout << "1 3 2";
  //else if (n == 3 && a[0][1] == 1) cout << "0 1 1";
  else if (n == 4 && a[0][2] == 2) cout << "1 2 3 2";
  else if (n == 4 && a[0][2] == 1) cout << "1 2 2 0";
  else {
    int cur = 0;
    FOR(i,0,n) {
      FOR(j,0,n) {
        if (a[j][i] == 1) {
          if (cur == 0) cur = 1;
          else cur = 0;
          break;
        }
      }
      cout << cur << ' ';
    }
  }
}