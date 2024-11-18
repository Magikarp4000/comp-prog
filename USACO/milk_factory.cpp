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

const int MAXN = 101;
int n;
vector<int> v[MAXN];
bool z[MAXN];

void dfs(int s) {
  if (z[s]) return;
  z[s] = 1;
  FORX(u,v[s]) dfs(u);
}

bool check(int s) {
  FOR(i,1,n+1) z[i] = 0;
  dfs(s);
  FOR(i,1,n+1) if (!z[i]) return 0;
  return 1;
}

int main() {
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n-1) {
    int a,b; cin >> a >> b;
    v[b].PB(a);
  }
  FOR(i,1,n+1) {
    if (check(i)) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}