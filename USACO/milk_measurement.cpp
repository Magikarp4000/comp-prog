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

int speed[100];

int main() {
  OPTM;
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
  int n; cin >> n;
  map<string,int> mp;
  mp["Bessie"] = 7;
  mp["Elsie"] = 7;
  mp["Mildred"] = 7;
  pair<int,pair<string,int>> a[n];
  US<string> s;
  FORX(u,mp) s.insert(u.F);
  FOR(i,0,n) {
    cin >> a[i].F >> a[i].S.F >> a[i].S.S;
  }
  sort(a,a+n);
  int res = 0;
  int last = 0;
  FOR(i,0,n) {
    int mx = -INF, oldmx = -INF;
    FORX(u,mp) oldmx = max(oldmx,u.S);
    US<string> tmp;
    FORX(u,s) tmp.insert(u);
    mp[a[i].S.F] += a[i].S.S;
    FORX(u,mp) mx = max(mx,u.S);
    s.clear();
    FORX(u,mp) if (u.S == mx) s.insert(u.F);
    bool change = 0;
    if (s.size() != tmp.size()) change = 1;
    else {
      FORX(u,s) if (!tmp.count(u)) change = 1;
    }
    if (a[i].F != last && change) {
      res++;
      last = a[i].F;
    }
  }
  cout << res;
}