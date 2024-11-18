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

const int MAXN = 100;
int n;
string x,y;
UM<string,string> pa;
map<string,vector<string>> v;
bool related = 0;
UM<string,int> depth;
string root;

void dfs(string s, string p) {
  if (pa[s] == "_") root = s;
  FORX(u,v[s]) {
    if (u == p) continue;
    if (u == y) related = 1;
    dfs(u,s);
  }
}

void dfs1(string s, string p) {
  FORX(u,v[s]) {
    if (u == p) continue;
    depth[u] = depth[s]+1;
    dfs1(u,s);
  }
}

PII scrutinize(string a, string b) {
  int k = 0;
  string s = a;
  while (s != "_") {
    if (s == b) return {k,0};
    FORX(u,v[s]) {
      if (u == pa[s]) continue;
      if (u == b) return {k,1};
    }
    s = pa[s];
    k++;
  }
  return {0,2};
}

int main() {
  freopen("family.in", "r", stdin);
  freopen("family.out", "w", stdout);
  OPTM;
  cin >> n >> x >> y;
  FOR(i,0,n) {
    string a,b; cin >> a >> b;
    v[a].PB(b);
    v[b].PB(a);
    pa[b] = a;
    if (!pa.count(a)) pa[a] = "_"; 
  }
  dfs(x,"_");
  if (!related) {
    cout << "NOT RELATED";
    return 0;
  }
  depth[root] = 0;
  dfs1(root,".");
  if (depth[x] < depth[y]) swap(x,y);
  PII res = scrutinize(x,y);
  if (res.S == 2) cout << "COUSINS";
  else if (res.S == 1) {
    if (res.F == 1) cout << "SIBLINGS";
    else {
      cout << y << " is the ";
      FOR(i,0,res.F-2) cout << "great-";
      cout << "aunt of " << x;
    }
  }
  else if (res.S == 0) {
    if (res.F == 1) cout << y << " is the mother of " << x;
    else {
      cout << y << " is the ";
      FOR(i,0,res.F-2) cout << "great-";
      cout << "grand-mother of " << x;
    }
  }
}