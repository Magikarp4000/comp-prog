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

const int MAXN = 1e5+1;
int n;
int d[MAXN];

int main() {
  OPTM;
  cin >> n;
  FOR(i,0,n-1) {
    int a,b; cin >> a >> b;
    d[a]++;
    d[b]++;
  }
  int res = n-1;
  FOR(i,1,n+1) {
    int j = 1;
    int extra = i == 1 ? 1 : 0;
    while (j < d[i]+extra) {
      j *= 2;
      res++;
    }
  }
  cout << res;
}