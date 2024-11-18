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

const int MAXN = 5e4+1;
int n,k;
int a[MAXN];


bool check(int x) {
  bool z[MAXN];
  FOR(i,0,MAXN) z[i] = 0;
  int cur = 0, i = 0;
  FOR(_,0,k) {
    while (i < n && a[i] <= a[cur]+2*x) {
      z[i] = 1;
      i++;
    }
    if (i >= n) return 1;
    cur = i;
  }
  FOR(i,0,n) if (!z[i]) return 0;
  return 1;
}

int main() {
  freopen("angry.in","r",stdin);
  freopen("angry.out","w",stdout);
  OPTM;
  cin >> n >> k;
  FOR(i,0,n) cin >> a[i];
  sort(a,a+n);
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l+r)/2;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << l;
}