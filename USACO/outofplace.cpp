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

const int MAXN = 100;
int n;
int a[MAXN];

bool check() {
  FOR(i,1,n) {
    if (a[i] < a[i-1]) return 0;
  }
  return 1;
}

bool check1(vector<int> v) {
  FOR(i,1,int(v.size())) {
    if (v[i] < v[i-1]) return 0;
  }
  return 1;
}

int main() {
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
  OPTM;
  cin >> n;
  FOR(i,0,n) cin >> a[i];
  if (check()) {cout << 0; return 0;}
  vector<int> v;
  v.PB(a[0]);
  FOR(i,1,n) {
    if (a[i] == a[i-1]) continue;
    v.PB(a[i]);
  }
  int vn = v.size();
  int p;
  FOR(i,1,vn) {
    if (v[i] < v[i-1]) {
      p = i;
      break;
    }
  }
  vector<int> tmp,tmp1;
  FOR(i,0,vn) {
    if (i != p) tmp.PB(v[i]);
    if (i != p-1) tmp1.PB(v[i]);
  }
  if (check1(tmp)) {
    int start;
    FOR(i,0,vn) {
      if (v[i] > v[p]) {
        start = i;
        break;
      }
    }
    cout << p-start;
  }
  else if (check1(tmp1)) {
    int endd;
    for (int i = vn-1; i >= 0; i--) {
      if (v[i] < v[p-1]) {
        endd = i;
        break;
      }
    }
    cout << endd-(p-1);
  }
}