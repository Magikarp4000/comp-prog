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

const int MAXN = 1e6+1;
int n,k;
ll d[MAXN];
ll a[MAXN];

int main() {
  freopen("stacking.in", "r", stdin);
  freopen("stacking.out", "w", stdout);
  OPTM;
  cin >> n >> k;
  FOR(i,0,k) {
    int a,b; cin >> a >> b;
    d[a-1]++; // 0-indexing
    d[b]--; // 0-indexing
  }
  a[0] = d[0];
  FOR(i,1,n) a[i] = a[i-1]+d[i];
  sort(a,a+n);
  cout << a[n/2];
}