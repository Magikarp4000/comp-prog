#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 1e12
#define ln '\n'
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define FOR(i,a,b,c) for (int i = a; i < b; i += c)
#define FORR(i,a,b,c) for (int i = a; i > b; i -= c)
#define FORA(u, arr) for (auto u : arr)
#define pb push_back
#define F first
#define S second


int main() {
  int N;
  cin >> N;
  vector<int> g, l;
  FOR(i,0,N,1) {
    char a;
    int b;
    cin >> a >> b;
    if (a == 'G') g.pb(b);
    else l.pb(b);
  }
  sort(g.begin(), g.end(), greater<int>());
  sort(l.begin(), l.end());
  int res = 0;
  FOR(i,0,g.size(),1) {
    FOR(j,0,l.size(),1) {
      if (g[i] > l[j]) {
        res++;
        break;
      }
    }
  }
  int res2 = 0;
  FOR(i,0,l.size(),1) {
    FOR(j,0,g.size(),1) {
      if (l[i] < g[j]) {
        res2++;
        break;
      }
    }
  }
  cout << min(res, res2);
}

