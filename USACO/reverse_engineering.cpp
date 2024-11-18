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

const int MAXN = 1e2+1;
int n,m;
string s;
bool t;
vector<string> a,b;
bool az[MAXN], bz[MAXN];

int main() {
  OPTM;
  int T; cin >> T;
  while (T--) {
    a.clear(); b.clear();
    FOR(i,0,MAXN) {
      az[i] = 0;
      bz[i] = 0;
    }
    cin >> n >> m;
    FOR(i,0,m) {
      cin >> s >> t;
      if (t == 0) a.PB(s);
      else b.PB(s);
    }
    int an = a.size(), bn = b.size();
    bool good = 1, good1 = 1;
    FOR(_,0,50) {
      FOR(i,0,an) {
        if (az[i]) continue;
        bool ok1 = 0;
        FOR(j,0,n) {
          bool ok = 1;
          FOR(k,0,bn) {
            if (bz[k]) continue;
            if (b[k][j] == a[i][j]) {
              ok = 0;
              break;
            }
          }
          if (ok) {
            ok1 = 1;
            break;
          }
        }
        if (ok1) az[i] = 1;
      }
      FOR(i,0,bn) {
        if (bz[i]) continue;
        bool ok1 = 0;
        FOR(j,0,n) {
          bool ok = 1;
          FOR(k,0,an) {
            if (az[k]) continue;
            if (a[k][j] == b[i][j]) {
              ok = 0;
              break;
            }
          }
          if (ok) {
            ok1 = 1;
            break;
          }
        }
        if (ok1) bz[i] = 1;
      }
    }
    FOR(i,0,an) {
      if (az[i]) continue;
      bool ok1 = 0;
      FOR(j,0,n) {
        bool ok = 1;
        FOR(k,0,bn) {
          if (bz[k]) continue;
          if (b[k][j] == a[i][j]) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          ok1 = 1;
          break;
        }
      }
      if (!ok1) good = 0;
    }
    FOR(i,0,bn) {
      if (bz[i]) continue;
      bool ok1 = 0;
      FOR(j,0,n) {
        bool ok = 1;
        FOR(k,0,an) {
          if (az[k]) continue;
          if (a[k][j] == b[i][j]) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          ok1 = 1;
          break;
        }
      }
      if (!ok1) good1 = 0;
    }
    if (!good && !good1) cout << "LIE";
    else cout << "OK";
    cout << ln;
  }
}