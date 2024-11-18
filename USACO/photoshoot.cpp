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

int n;
string s;

int main() {
  OPTM;
  cin >> n >> s;
  string p;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == 'G' && s[i+1] == 'H') p += 'B';
    else if (s[i] == 'H' && s[i+1] == 'G') p += 'A';
  }
  int res = p[p.size()-1] == 'B' ? 1 : 0;
  FOR(i,1,(int)p.size()) if (p[i] != p[i-1]) res++;
  cout << res;
}