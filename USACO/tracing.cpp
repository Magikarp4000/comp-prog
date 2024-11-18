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

const int MAXN = 101;
int n,m;
string s;
vector<pair<int,PII>> v;
int num = 0, smol = INF, big = -INF;
bool ayo = 0;

void check(int x) {
  bool ok = 0;
  FOR(lim,0,m+1) {
    bool z[n+1];
    int k[n+1];
    FOR(i,0,n+1) {
      z[i] = 0;
      k[i] = 0;
    }
    z[x] = 1;
    FOR(i,0,m) {
      int a = v[i].S.F, b = v[i].S.S;
      bool doescount = 1;
      if (!z[b]) doescount = 0;
      if (z[a] && k[a] < lim) {
        z[b] = 1;
        k[a]++;
      }
      if (doescount && k[b] < lim) {
        z[a] = 1;
        k[b]++;
      }
    }
    bool nono = 0;
    FOR(i,1,n+1) if (z[i] != s[i-1]-'0') nono = 1;
    if (!nono) {
      ok = 1;
      smol = min(smol,lim);
      big = max(big,lim);
      if (lim == m) ayo = 1;
    }
  }
  if (ok) num++;
}

int main() {
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);
  OPTM;
  cin >> n >> m >> s;
  FOR(i,0,m) {
    int t,a,b; cin >> t >> a >> b;
    v.PB({t,{a,b}});
  }
  sort(ALL(v));
  FOR(i,1,n+1) check(i);
  cout << num << ' ' << smol << ' ';
  if (ayo) cout << "Infinity";
  else cout << big;
}