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
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  int n,m; cin >> n >> m;
  string a[n],b[n];
  FOR(i,0,n) cin >> a[i];
  FOR(i,0,n) cin >> b[i];
  int res = 0;
  FOR(i,0,m) {
    US<char> s,s1;
    FOR(j,0,n) {
      s.insert(a[j][i]);
      s1.insert(b[j][i]);
    }
    bool ok = 1;
    FORX(u,s) if (s1.count(u)) ok = 0;
    if (ok) res++;
  }
  cout << res;
}