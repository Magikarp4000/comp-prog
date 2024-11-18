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

const int MAXN = 1e3+2;
int n,m;
ll dp[MAXN][MAXN];
ll xf,yf,xb,yb;
pair<ll,ll> f[MAXN], b[MAXN];
string fs, bs;
UM<char,PII> mp;

ll dist(pair<ll,ll> p1, pair<ll,ll> p2) {
    return (p2.F-p1.F)*(p2.F-p1.F)+(p2.S-p1.S)*(p2.S-p1.S);
}

signed main() {
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    OPTM;
    mp['N'] = {0,1};
    mp['E'] = {1,0};
    mp['S'] = {0,-1};
    mp['W'] = {-1,0};
    cin >> n >> m;
    cin >> xf >> yf >> xb >> yb;
    cin >> fs >> bs;
    f[0] = {xf,yf};
    b[0] = {xb,yb};
    FOR(i,1,n+1) {
        f[i] = f[i-1];
        f[i].F += mp[fs[i-1]].F;
        f[i].S += mp[fs[i-1]].S;
    }
    FOR(i,1,m+1) {
        b[i] = b[i-1];
        b[i].F += mp[bs[i-1]].F;
        b[i].S += mp[bs[i-1]].S;
    }
    FOR(i,0,n+2) dp[i][0] = LLINF;
    FOR(j,0,m+2) dp[0][j] = LLINF;
    FOR(i,1,n+2) {
        FOR(j,1,m+2) {
            if (i == 1 && j == 1) dp[i][j] = 0;
            else {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+dist(f[i-1], b[j-1]);
            }
        }
    }
    cout << dp[n+1][m+1];
}