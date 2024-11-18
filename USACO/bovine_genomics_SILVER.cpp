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

const int MAXN = 500;
int n,m;
int A[MAXN][MAXN],B[MAXN][MAXN];
map<char,int> mp;

bool check(int a, int b, int c) {
  US<int> s,s1;
  FOR(i,0,n) {
    int x = 16*A[i][a]+4*A[i][b]+A[i][c];
    int x1 = 16*B[i][a]+4*B[i][b]+B[i][c];
    s.insert(x);
    s1.insert(x1);
  }
  FORX(u,s1) if (s.count(u)) return 0;
  return 1;
}

int main() {
  OPTM;
  mp['A'] = 0;
  mp['C'] = 1;
  mp['G'] = 2;
  mp['T'] = 3;
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  cin >> n >> m;
  FOR(i,0,n) {
    FOR(j,0,m) {
      char x; cin >> x;
      A[i][j] = mp[x];
    }
  }
  FOR(i,0,n) {
    FOR(j,0,m) {
      char x; cin >> x;
      B[i][j] = mp[x];
    }
  }
  int res = 0;
  FOR(i,0,m) {
    FOR(j,i+1,m) {
      FOR(k,j+1,m) {
        if (check(i,j,k)) res++;
      }
    }
  }
  cout << res;
}