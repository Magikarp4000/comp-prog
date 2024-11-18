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

const int MAXN = 1e6+5;
int n,MOD;
string s;
int p[MAXN];

signed main() {
    OPTM;
    cin >> n >> MOD >> s;
    p[0] = 1LL;
    FOR(i,1,n+1) p[i] = (p[i-1]*2LL)%MOD;
    int lb = 0, ub = 0, cur = 0, res = 1LL;
    FOR(i,0,n) {
        if (s[i] == 'L') {
            cur++;
            ub = max(ub,cur);
        }
        else {
            int tcur = cur+1;
            int tub = max(ub,tcur);
            int rem = n-i-1;
            if (tub-lb == 1) res = (res+p[(rem+1)/2]+p[rem/2]-1LL+MOD)%MOD;
            else if (tub-lb == 2) {
                if (tcur == (tub+lb)/2) res = (res+p[(rem+1)/2])%MOD;
                else res = (res+p[rem/2])%MOD;
            }
            cur--;
            lb = min(lb,cur);
        }
    }
    cout << res;
}