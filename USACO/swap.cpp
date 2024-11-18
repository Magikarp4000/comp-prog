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

const int MAXN = 102;
int n,k,a1,a2,b1,b2;
vector<vector<int>> p;

int main() {
  freopen("swap.in","r",stdin);
  freopen("swap.out","w",stdout);
  OPTM;
  cin >> n >> k >> a1 >> a2 >> b1 >> b2;
  vector<int> tmp,cur;
  FOR(i,1,n+1) {
    cur.PB(i);
    tmp.PB(i);
  }
  reverse(cur.begin()+a1-1, cur.begin()+a2);
  reverse(cur.begin()+b1-1, cur.begin()+b2);
  int cnt = 1;
  while (cur != tmp) {
    reverse(cur.begin()+a1-1, cur.begin()+a2);
    reverse(cur.begin()+b1-1, cur.begin()+b2);
    cnt++;
  }
  int m = k%cnt;
  FOR(i,0,m) {
    reverse(tmp.begin()+a1-1, tmp.begin()+a2);
    reverse(tmp.begin()+b1-1, tmp.begin()+b2);
  }
  FORX(u,tmp) cout << u << ln;
}