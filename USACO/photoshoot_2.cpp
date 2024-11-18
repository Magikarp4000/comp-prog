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
  int a[N], x;
  map<int,int> b;
  FOR(i,0,N,1) {
    cin >> a[i];
  }
  FOR(i,0,N,1) {
    cin >> x;
    b[x] = i;
  }
  FOR(i,0,N,1) {
    a[i] = b[a[i]];
  }
  int res = 0, cur = -1;
  FOR(i,0,N,1) {
    if (a[i] > cur) cur = a[i];
    else res++;
  }
  cout << res;
}