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

ll k;
int n;

int main() {
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  OPTM;
  cin >> k >> n;
  FOR(i,0,n) {
    ll x; cin >> x;
    ll y = sqrt(k+(x*(x+1))/2);
    if (y*y == k+(x*(x+1))/2) y--;
    //cout << y << ' ';
    if (y*(y+1)/2 >= k) {
      ll d = 0, v = 0;
      while (d < k) {
        v++;
        d += v;
      }
      cout << v << ln;
    }
    else {
      ll leftover = ceil(floor((k-(y*y-(x*(x+1)/2)+x)))/y);
      ll res = y+y-x+leftover;
      cout << res << ln;
    }
  }
}