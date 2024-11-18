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

string s,t,res;

int main() {
  freopen("censor.in","r",stdin);
  freopen("censor.out","w",stdout);
  OPTM;
  cin >> s >> t;
  int sn = s.size(), tn = t.size();
  FOR(i,0,sn) {
    res.PB(s[i]);
    int rn = res.size();
    bool ok = 1;
    if (rn >= tn) {
      string tmp;
      FOR(j,rn-tn,rn) tmp.PB(res[j]);
      if (tmp == t) ok = 0;
    }
    if (!ok) FOR(j,0,tn) res.pop_back();
  }
  cout << res;
}