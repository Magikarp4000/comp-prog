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

int n;
string cows[7] = {
  "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"
};
UM<string,int> mp;

int main() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  OPTM;
  FOR(i,0,7) mp[cows[i]] = 0;
  cin >> n;
  FOR(i,0,n) {
    string s; int x; cin >> s >> x;
    mp[s] += x;
  }
  vector<pair<int,string>> v;
  FORX(u,mp) v.PB({u.S,u.F});
  sort(v.begin(), v.end());
  int mi = v[0].F;
  FOR(i,0,7) {
    if (v[i].F != mi) {
      if (i == 6 || v[i].F != v[i+1].F) {
        cout << v[i].S << ln;
        return 0;
      }
      else {
        cout << "Tie\n";
        return 0;
      }
    }
  }
  cout << "Tie\n";
}