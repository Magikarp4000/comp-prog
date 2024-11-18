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
vector<int> v[MAXN];
int c[MAXN];

void dfs(int s, int p) {
  int cur = 1;
  FORX(u,v[s]) {
    if (u == p) continue;
    while (cur == c[s] || (p != -1 && cur == c[p])) cur++;
    c[u] = cur;
    dfs(u,s);
    cur++;
  }
}

int main() {
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n-1) {
    int a,b; cin >> a >> b;
    v[a].PB(b);
    v[b].PB(a);
  }
  c[1] = 1;
  dfs(1,-1);
  cout << *max_element(c,c+n+1);
}