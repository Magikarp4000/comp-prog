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

struct Boot {
  int A,B,C;
};

const int MAXN = 1e5+1;
int n,b;
set<int> s;
PQ<PII> pq;
int a[MAXN], d[MAXN];
bool z[MAXN];
vector<Boot> v;

bool cmp(Boot& x, Boot& y) {
  return x.A > y.A;
}

int main() {
  freopen("snowboots.in","r",stdin);
  freopen("snowboots.out","w",stdout);
  OPTM;
  cin >> n >> b;
  FOR(i,0,n) cin >> a[i];
  FOR(i,1,n-1) pq.push({a[i],i});
  FOR(i,0,b) {
    int x,y; cin >> x >> y;
    v.PB({x,y,i});
  }
  sort(ALL(v),cmp);
  FOR(i,0,n) s.insert(i);
  FOR(i,0,n-1) d[i] = 1;
  int cur = 1;
  FOR(i,0,b) {
    while (!pq.empty() && pq.top().F > v[i].A) {
      int f = pq.top().F, idx = pq.top().S;
      pq.pop();
      auto it = s.find(idx);
      it--;
      int prev = *it;
      d[prev] += d[idx];
      d[idx] = 0;
      s.erase(idx);
      cur = max(cur,d[prev]);
    }
    if (cur > v[i].B) z[v[i].C] = 0;
    else z[v[i].C] = 1;
  }
  FOR(i,0,b) cout << z[i] << ln;
}