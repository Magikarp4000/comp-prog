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
int n,m;
vector<ll> v[MAXN];
int c[MAXN];
bool z[MAXN];
vector<vector<ll>> comps;
ll br[MAXN], uh[MAXN];

void dfs(ll s, int idx) {
  if (z[s]) return;
  z[s] = 1;
  c[s] = idx;
  comps[idx].PB(s);
  FORX(u,v[s]) dfs(u,idx);
}

int main() {
  OPTM;
  int T; cin >> T;
  while (T--) {
    FOR(i,0,MAXN+1) {
      v[i].clear();
      z[i] = 0;
      c[i] = 0;
      br[i] = LLINF;
      uh[i] = LLINF;
    }
    comps.clear();
    cin >> n >> m;
    FOR(i,0,m) {
      ll a,b; cin >> a >> b;
      v[a].PB(b);
      v[b].PB(a);
    }
    int cur = 0;
    FOR(i,1,n+1) {
      if (!z[i]) {
        vector<ll> tmp;
        comps.PB(tmp);
        dfs(i,cur);
        cur++;
      }
    }
    br[c[1]] = 0;
    uh[c[n]] = 0;
    FOR(i,0,cur) sort(ALL(comps[i]));
    int i = 0;
    ll j = 1;
    while (i < comps[c[n]].size() && j <= n) {
      while (j <= n && (c[n] == c[j] || i == comps[c[n]].size()-1 || abs(comps[c[n]][i]-j) < abs(comps[c[n]][i+1]-j))) {
        if (c[n] == c[j]) j++;
        else {
          uh[c[j]] = min(uh[c[j]], (comps[c[n]][i]-j)*(comps[c[n]][i]-j));
          j++;
        }
      }
      i++;
    }
    i = comps[c[1]].size()-1; j = n;
    while (i > -1 && j >= 1) {
      while (j >= 1 && (c[1] == c[j] || i == 0 || abs(comps[c[1]][i]-j) < abs(comps[c[1]][i-1]-j))) {
        if (c[1] == c[j]) j--;
        else {
          br[c[j]] = min(br[c[j]], (comps[c[1]][i]-j)*(comps[c[1]][i]-j));
          j--;
        }
      }
      i--;
    }
    ll res = LLINF;
    FOR(i,0,(int)comps.size()) {
      res = min(res, br[i]+uh[i]);
    }
    cout << res << ln;
  }
}