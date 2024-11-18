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

const int MAXN = 1e5+1;
int n,k;
string s;
char a[MAXN];

int main() {
  OPTM;
  int T; cin >> T;
  while (T--) {
    cin >> n >> k >> s;
    FOR(i,0,n) a[i] = '.';
    int g = -INF, h = -INF, res = 0;
    FOR(i,0,n) {
      if (s[i] == 'G' && i-k > g) {
        int pos = min(i+k,n-1);
        while (a[pos] == 'H') pos--;
        a[pos] = 'G';
        g = pos;
        res++;
      }
      if (s[i] == 'H' && i-k > h) {
        int pos = min(i+k,n-1);
        while (a[pos] == 'G') pos--;
        a[pos] = 'H';
        h = pos;
        res++;
      }
    }
    cout << res << ln;
    FOR(i,0,n) cout << a[i];
    cout << ln;
  }
}