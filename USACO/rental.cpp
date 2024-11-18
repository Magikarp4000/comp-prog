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

bool cmp(const PII& x, const PII& y) {
  return x.F > y.F;
}

bool cmp2(const ll& x, const ll& y) {
  return x > y;
}
 
int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);
  OPTM;
  int n,m,r; cin >> n >> m >> r;
  ll a[n];
  FOR(i,0,n) cin >> a[i];
  sort(a,a+n,cmp2);
  pair<ll,ll> mk[m];
  FOR(i,0,m) cin >> mk[i].S >> mk[i].F;
  sort(mk,mk+m,cmp);
  ll nh[r];
  FOR(i,0,r) cin >> nh[i];
  sort(nh,nh+r);
  ll p2[r];
  p2[0] = 0;
  FOR(i,1,r+1) p2[i] = p2[i-1]+nh[i-1];
  
  ll res = p2[r]-p2[max(0,r-n)];
  ll cur1 = 0, cur2 = 0;
  int idx = 0;
  FOR(i,0,n) {
    ll cur = a[i];
    while (idx < m && cur > 0) {
      ll amount = min(cur,mk[idx].S);
      mk[idx].S -= amount;
      cur -= amount;
      cur1 += amount*mk[idx].F;
      if (mk[idx].S == 0) idx++;
    }
    cur2 = p2[r]-p2[max(0,r-(n-i-1))];
    res = max(res,cur1+cur2);
  }
  cout << res;
}