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

int m,n,k;

int main() {
  freopen("cowsignal.in","r",stdin);
  freopen("cowsignal.out","w",stdout);
  OPTM;
  cin >> m >> n >> k;
  FOR(i,0,m) {
    string s;
    FOR(j,0,n) {
      char c; cin >> c;
      FOR(l,0,k) s.PB(c);
    }
    FOR(j,0,k) cout << s << ln;
  }
}