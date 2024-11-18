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

const int n = 8;
int k;
string cows[n] = {
  "Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"
};
int a[n];
UM<string,int> mp;
vector<PII> v;

bool check(int a[]) {
  US<int> s[n];
  s[a[0]].insert(a[1]);
  s[a[n-1]].insert(a[n-2]);
  FOR(i,1,n-1) {
    s[a[i]].insert(a[i-1]);
    s[a[i]].insert(a[i+1]);
  }
  FORX(u,v) {
    if (!s[u.F].count(u.S)) return 0;
  }
  return 1;
}

int main() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);
  OPTM;
  sort(cows,cows+n);
  FOR(i,0,n) mp[cows[i]] = i;
  FOR(i,0,n) a[i] = i;
  cin >> k;
  FOR(i,0,k) {
    string x; cin >> x;
    string trash;
    FOR(_,0,4) cin >> trash;
    string y; cin >> y;
    v.PB({mp[x],mp[y]});
  }
  do {
    if (check(a)) {
      FORX(u,a) cout << cows[u] << ln;
      return 0;
    }
  } while (next_permutation(a,a+n));
}