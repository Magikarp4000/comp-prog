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
vector<pair<int,char>> v[MAXN];
bool z[MAXN];
int col[MAXN];
int res = 0;
bool ok = 1;

void dfs(int s, int p) {
  z[s] = 1;
  int opp = col[s] == 1 ? 2 : 1;
  FORX(u,v[s]) {
    int k = u.F; char c = u.S;
    if (col[k]) {
      if ((c == 'S' && col[s] != col[k]) || (c == 'D' && opp != col[k])) {
        ok = 0;
      	return;
      }
    }
    else {
      col[k] = c == 'S' ? col[s] : opp;
      dfs(k,s);
    }
  }
}

int main() {
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
  OPTM;
  int n,m; cin >> n >> m;
  FOR(i,0,m) {
    char c; int a,b;
    cin >> c >> a >> b;
    v[a].PB({b,c});
    v[b].PB({a,c});
  }
  FOR(i,1,n+1) {
    if (!z[i]) {
      col[i] = 1;
      dfs(i,-1);
      if (!ok) {
        cout << 0;
        return 0;
      }
      else res++;
    }
  }
  cout << 1;
  FOR(i,0,res) cout << 0;
}