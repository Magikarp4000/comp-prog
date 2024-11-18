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

struct Edge {
  int a,b,w;
};

const int MAXN = 1e5+1, MAXW = 1e9;
int n,m;
int p[MAXN];
vector<Edge> inp;
vector<int> v[MAXN];
vector<US<int>> comps;
bool z[MAXN];
int c[MAXN];

void dfs(int s, int k) {
  if (z[s]) return;
  z[s] = 1;
  c[s] = k;
  comps[k].insert(s);
  FORX(u,v[s]) dfs(u,k);
}

bool check(int x) {
  FOR(i,1,n+1) {
    v[i].clear();
    z[i] = 0;
    c[i] = -1;
  }
  comps.clear();
  FOR(i,0,m) {
    if (inp[i].w >= x) {
      v[inp[i].a].PB(inp[i].b);
      v[inp[i].b].PB(inp[i].a);
    }
  }
  int cur = 0;
  FOR(i,1,n+1) {
    if (!z[i]) {
      US<int> tmp;
      comps.PB(tmp);
      dfs(i,cur);
      cur++;
    }
  }
  FOR(i,1,n+1) {
    if (!comps[c[p[i]]].count(i)) return 0;
  }
  return 1;
}

int bsearch() {
  int l = 1, r = MAXW;
  while (l < r) {
    int mid = r+(l-r)/2;
    if (check(mid)) {
      if (mid == MAXW) return -1;
      if (!check(mid+1)) return mid;
      l = mid+1;
    }
    else {
      if (check(mid-1)) return mid-1;
      r = mid;
    }
  }
  return l;
}

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  OPTM;
  cin >> n >> m;
  FOR(i,1,n+1) cin >> p[i];
  FOR(i,0,m) {
    int a,b,w; cin >> a >> b >> w;
    inp.PB({a,b,w});
  }
  cout << bsearch();
}