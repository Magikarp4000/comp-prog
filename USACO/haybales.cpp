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

vector<int> v;
int n,q;

int main() {
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  OPTM;
  cin >> n >> q;
  FOR(i,0,n) {
    int x; cin >> x;
    v.PB(x);
  }
  sort(ALL(v));
  FOR(i,0,q) {
    int a,b; cin >> a >> b;
    cout << upper_bound(ALL(v),b) - lower_bound(ALL(v),a) << ln;
  }
}