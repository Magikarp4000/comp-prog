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
#define double long long
#define POG double

const int MAXN = 5e4+1;
const double EPS = 0.5;
int n;
vector<double> v;
double dpl[MAXN],dpr[MAXN];
UM<int,int> mp;

double roundp5(double x) {
  double f = floor(x);
  if (x >= f+0.5) return f+1-x <= x-(f+0.5) ? f+1 : f+0.5;
  else return f+0.5-x <= x-f ? f+0.5 : f;
  /*if (x == f) return f;
  else if (x <= f+0.5) return f+0.5;
  else return f+1;*/
}

bool check(double x) {
  double l = v[0], r = v[n-1];
  while (l < r) {
    double mid = (l+r)/2;
    ll c = *lower_bound(ALL(v),mid-x);
    ll cur = x-2;
    while (c > v[0] && cur > 0) {
      ll tmp = c;
      c = *lower_bound(ALL(v),tmp-cur);
      if (c == tmp) break;
      cur -= 2;
    }
    if (c != v[0]) r = mid;
    else l = mid+1;
  }
  auto it = upper_bound(ALL(v),l+x);
  it--;
  ll d = *it;
  ll cur1 = x-2;
  while (d < v[n-1] && cur1 > 0) {
    ll tmp1 = d;
    auto it1 = upper_bound(ALL(v),tmp1+cur1);
    it1--;
    d = *it1;
    if (d == tmp1) break;
    cur1 -= 2;
  }
  if (d != v[n-1]) return 0;
  return 1;
}

int main() {
  freopen("angry.in","r",stdin);
  freopen("angry.out","w",stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n) {
    double x; cin >> x;
    v.PB(x*2);
  }
  sort(ALL(v));
  FOR(i,0,n) mp[v[i]] = i;
  FOR(i,1,n) dpl[i] = max(dpl[i-1]+2, v[i]-v[i-1]);
  FORR(i,n-2,-1) dpr[i] = max(dpr[i+1]+2, v[i+1]-v[i]);
  double l = 0, r = 1e9;
  while (l < r) {
    double mid = (l+r)/2;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  string dec = ".0";
  if (l/2*2 == l-1) dec = ".5";
  cout << l/2 << dec;
}