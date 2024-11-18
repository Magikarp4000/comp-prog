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

const int MAXN = 1e5+1, MAXP = 5e6+1;
int n;
int a[MAXN];
bool z[MAXP*2];
US<int> primes, primes1;
int dp[MAXP];
/*int a1[] = {1, 5, 17, 29, 41, 73, 113, 241, 577, 1097, 2029, 3797, 8641, 148381, 204329, 277097, 380557, 413477, 461101, 517229, 671501, 763513, 883273, 992153, 1034101, 1082881, 1206113, 1291501, 1426169, 1541209, 1574501, 1639613, 1772501, 1835017, 1898417, 2071997, 2176409, 2290213, 2425837, 2509649, 2648101, 2755429, 2776769, 2883997, 2946257, 3018733, 3151913, 3228161, 3364253, 3488809, 3574061, 3727693, 3893557, 4010701, 4064033, 4121441, 4181461, 4325677, 4406401, 4509793, 4627421, 4755701, 4800073, 4861429};
int a2[] = {3, 7, 11, 31, 107, 251, 13291, 40699, 195359, 312251, 352271, 459383, 562519, 671911, 725983, 858427, 917519, 1035343, 1097543, 1164511, 1235263, 1318487, 1424023, 1477807, 1587527, 1632143, 1700287, 1770331, 1875619, 1911919, 1974163, 2081719, 2154143, 2237399, 2343799, 2455547, 2494031, 2596163, 2715683, 2829767, 2960267, 3110059, 3179339, 3302119, 3388907, 3548219, 3717859, 3818071, 3856907, 3996283, 4082719, 4199971, 4275679, 4397923, 4467191, 4629827, 4736243, 4791643, 4869239};
US<int> s1,s2;*/
vector<int> v1,v2,v3,v4;

int main() {
  //freopen("berries.in","r",stdin);
  //freopen("berries.out","w",stdout);
  OPTM;
  //FOR(i,0,10) s1.insert(a1[i]);
  //FOR(i,0,59) s2.insert(a1[i]);
  primes.insert(1);
  FOR(i,2,MAXP) {
    if (z[i]) continue;
    primes.insert(i);
    for (int j = i; j < MAXP; j += i) z[j] = 1;
  }
  FORX(u,primes) {
    if ((u%4) == 0) v1.PB(u);
    else if ((u%4) == 1) v2.PB(u);
    else if ((u%4) == 2) v3.PB(u);
    else if ((u%4) == 3) v4.PB(u);
  }
  sort(ALL(v1));
  sort(ALL(v2));
  sort(ALL(v3));
  sort(ALL(v4));
  int T; cin >> T;
  while (T--) {
    cin >> n;
    int lose = INF, win = INF;
    FOR(i,0,n) cin >> a[i];
    int lpos,wpos;
    FOR(i,0,n) {
      vector<int>::iterator it;
      if (a[i]%4 == 0) {
        if (lose > a[i]/4+1) {
          lose = a[i]/4+1;
          lpos = i;
        };
        continue;
      }
      else if (a[i]%4 == 1) it = upper_bound(ALL(v2), a[i]);
      else if (a[i]%4 == 2) it = upper_bound(ALL(v3), a[i]);
      else if (a[i]%4 == 3) it = upper_bound(ALL(v4), a[i]);
      it--;
      int sussy = *it;
      int cur = (a[i]-sussy)/4+1;
      //cout << cur << ' ';
      if (win > cur) {
        win = cur;
        wpos = i;
      }
    }
    if (win == lose) {
      if (wpos < lpos) cout << "Farmer John";
      else cout << "Farmer Nhoj";
    }
    else if (win > lose) cout << "Farmer Nhoj";
    else cout << "Farmer John";
    cout << ln;
  }
}