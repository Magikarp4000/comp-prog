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

const int MAXN = 2e5+1;
int k,m,n;
UM<int,ll> mp;
vector<int> v,w;
vector<ll> sum;

int main() {
  OPTM;
  cin >> k >> m >> n;
  FOR(i,0,k) {
    int x; ll b;
    cin >> x >> b;
    mp[x] = b;
    v.PB(x);
  }
  FOR(i,0,m) {
    int x; cin >> x;
    w.PB(x);
  }
  sort(ALL(v));
  sort(ALL(w));
  int i = 0;
  ll cur = 0;
  while (v[i] < w[0]) {
    cur += mp[v[i]];
    i++;
  }
  int start = i;
  sum.PB(cur);
  i = k-1;
  cur = 0;
  while (v[i] > w[m-1]) {
    cur += mp[v[i]];
    i--;
  }
  int endd = i;
  sum.PB(cur);
  i = start;
  int j = 0;
  queue<int> q;
  cur = 0;
  while (i <= endd && j < m-1) {
    while (j < m-1 && w[j+1] < v[i]) j++;
    ll one = 0, two = 0;
    while (i <= endd && v[i] < w[j+1]) {
      two += mp[v[i]];
      q.push(v[i]);
      cur += mp[v[i]];
      while (!q.empty() && abs(q.front()-w[j]) <= abs(max(w[j]+0.5, v[i]-(w[j+1]-v[i]-0.5))-q.front())) {
        cur -= mp[q.front()];
        q.pop();
      }
      one = max(one, cur);
      i++;
    }
    sum.PB(one);
    sum.PB(two-one);
    j++;
  }
  sort(ALL(sum), greater<ll>());
  ll res = 0;
  FOR(i,0,min(n,(int)sum.size())) res += sum[i];
  cout << res;
}