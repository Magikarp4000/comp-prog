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
double a[MAXN];

bool check(double x) {
  double b[MAXN], total = 0;
  FOR(i,0,n) {
    b[i] = a[i]-x;
    total += b[i];
  }
  double res = 0, cur = 0;
  FOR(i,1,n-1) {
    cur = max(b[i],b[i]+cur);
    res = max(res,cur);
  }
  if (res == 0) res = *max_element(b+1,b+n-1);
  if (total-res > 0) return 0;
  else return 1;
}

int main() {
  freopen("sabotage.in","r",stdin);
  freopen("sabotage.out","w",stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n) cin >> a[i];
  double l = 0, r = 1e5;
  while (l < r-1e-4) {
    double mid = (l+r)/2;
    if (check(mid)) r = mid;
    else l = mid+1e-4;
  }
  cout << setprecision(3) << fixed << l;
}