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

const int MAXN = 1e4+1, MAXP = 1240;
ll n,m;
ll dp[MAXP][MAXN];
vector<ll> p;
bool z[MAXN];

signed main() {
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    OPTM;
    cin >> n >> m;  
    FOR(i,0,n+1) dp[0][i] = 1;
    FOR(i,2,n+1) {
        if (z[i]) continue;
        p.PB((ll)i);
        for (int j = i; j < n+1; j += i) z[j] = 1;
    }
    int pn = p.size();
    FOR(i,0,pn) {
        FOR(j,0,n+1) {
            dp[i+1][j] = dp[i][j];
            for (ll k = p[i]; k <= j; k *= p[i]) {
                dp[i+1][j] = (dp[i+1][j]+(k*dp[i][j-k])%m)%m;
            }
        }
    }
    cout << dp[pn][n];
}