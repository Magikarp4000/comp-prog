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
vector<int> v[MAXN];
string t;
int comp[MAXN];
bool z[MAXN];

void dfs(int s) {
  z[s] = 1;
  FORX(u,v[s]) {
    if (z[u]) continue;
    if (t[u-1] != t[s-1]) continue;
    comp[u] = comp[s];
    dfs(u);
  }
}

int main() {
  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);
  OPTM;
  int n,m; cin >> n >> m;
  cin >> t;
  FOR(i,0,n-1) {
    int a,b; cin >> a >> b;
    v[a].PB(b);
    v[b].PB(a);
  }
  int cur = 1;
  FOR(i,1,n+1) {
    if (!z[i]) {
      comp[i] = cur;
      dfs(i);
      cur++;
    }
  }
  while (m--) {
    int a,b; char c;
    cin >> a >> b >> c;
    if (comp[a] != comp[b]) cout << 1;
    else if (t[a-1] == c) cout << 1;
    else cout << 0;
  }
}