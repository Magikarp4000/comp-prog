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

const int MAXN = 1000;
int n;
int g[MAXN][MAXN];

int main() {
  OPTM;
  cin >> n;
  FOR(i,0,n) FOR(j,0,n) cin >> g[i][j];
  int rres = 0, cres = 0;
  FOR(i,0,n) {
    int cur = 0;
    for (int j = 0; j < n; j += 2) cur += g[i][j];
    int cur1 = 0;
    for (int j = 1; j < n; j += 2) cur1 += g[i][j];
    rres += max(cur,cur1);
  }
  FOR(j,0,n) {
    int cur = 0;
    for (int i = 0; i < n; i += 2) cur += g[i][j];
    int cur1 = 0;
    for (int i = 1; i < n; i += 2) cur1 += g[i][j];
    cres += max(cur,cur1);
  }
  cout << max(rres,cres);
}