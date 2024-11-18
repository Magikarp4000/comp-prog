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

int main() {
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);
  OPTM;
  int n; cin >> n;
  int a[n];
  FOR(i,0,n) cin >> a[i];
  int consec = 1;
  FORR(i,n-2,-1) {
    if (a[i] > a[i+1]) break;
    consec++;
  }
  cout << n-consec << ln;
}