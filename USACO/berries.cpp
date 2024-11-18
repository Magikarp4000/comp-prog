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

const int MAXN = 1e3+1;
int n,k;
int a[MAXN], w[MAXN];
int res = 0;

int main() {
  freopen("berries.in","r",stdin);
  freopen("berries.out","w",stdout);
  OPTM;
  cin >> n >> k;
  FOR(i,0,n) cin >> a[i];
  sort(a,a+n,greater<int>());
  int maxb = *max_element(a,a+n);
  FOR(b,1,maxb+1) {
    FOR(i,0,n) w[i] = a[i];
    vector<int> v;
    int i = 0, cur = 0;
    while (i < n && cur < k/2) {
      while (w[i] >= b && cur < k/2) {
        v.PB(b);
        w[i] -= b;
        cur++;
      }
      i++;
    }
    i = 0;
    while (i < n) {
      while (w[i] >= b) {
        v.PB(b);
        w[i] -= b;
        cur++;
      }
      v.PB(w[i]);
      cur++;
      i++;
    }
    sort(ALL(v),greater<int>());
    int curres = 0;
    FOR(i,k/2,k) {
      if (i >= v.size()) break;
      curres += v[i];
    }
    res = max(res,curres);
  }
  cout << res;
}