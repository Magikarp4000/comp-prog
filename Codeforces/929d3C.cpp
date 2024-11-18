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
#define FORX(u,arr) for (auto u : arr)
#define PB push_back
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;
#define int long long

bool check(int a, int b, int c) {
    while (c%a == 0) c /= a;
    while (c%b == 0) c /= b;
    return (c == 1);
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        int a,b,l; cin >> a >> b >> l;
        int cura = 1;
        US<int> s;
        FOR(i,0,100) {
            int curb = 1;
            FOR(j,0,100) {
                if (cura*curb > l) break;
                if (l%(cura*curb) == 0) s.insert(l/(cura*curb));
                if (curb*b > l) break;
                else curb *= b;
            }
            if (cura*a > l) break;
            else cura *= a;
        }
        cout << s.size() << ln;
    }
}