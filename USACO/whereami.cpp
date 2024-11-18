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
string s;
US<string> a;

bool check(int i) {
  FOR(j,i,n+1) {
    string tmp;
    FOR(k,j-i,j) tmp += s[k];
    if (a.count(tmp)) return 0;
    a.insert(tmp);
  }
  return 1;
}

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  OPTM;
  cin >> n >> s;
  FOR(i,1,n+1) {
    a.clear();
    if (check(i)) {
      cout << i;
      return 0;
    }
  }
}