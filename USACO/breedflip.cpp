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

int n;
string a,b;
int res = 0;

int main() {
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);
  OPTM;
  cin >> n >> a >> b;
  bool equal = a[0] == b[0] ? 1 : 0;
  if (!equal) res++;
  FOR(i,1,n) {
    if (equal && a[i] != b[i]) {
      equal = 0;
      res++;
    }
    if (!equal && a[i] == b[i]) equal = 1;
  }
  cout << res;
}