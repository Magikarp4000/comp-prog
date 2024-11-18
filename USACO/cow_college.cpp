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

const int MAXN = 1e5+1, MAXC = 1e6+1;
ll n;
ll a[MAXN];
ll res = 0, c = 0;

int main() {
  OPTM;
  cin >> n;
  FOR(i,0,n) cin >> a[i];
  sort(a,a+n);
  ll i = 0, j = 0;
  while (i < MAXC) {
    while (j < n && a[j] < i) j++;
    if (j >= n) break;
    ll num = n-j;
    if (num*i > res) {
      res = num*i;
      c = i;
    }
    i++;
  }
  cout << res << ' ' << c;
}