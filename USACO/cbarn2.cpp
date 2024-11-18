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
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;
#define int long long

const int MAXN = 1e2+1, MAXK = 8;
int n,K;
int a[MAXN], dp[MAXN][MAXK], p[MAXN][MAXN];
int b[MAXN];

int solve(int shift) {
    FOR(i,0,n) b[i] = a[(i+shift)%n];
    FOR(i,0,n) {
        FOR(j,i+1,n) {
            p[i][j] = p[i][j-1]+(j-i)*b[j];
        }
    }
    FOR(i,0,n) FOR(j,1,K) dp[i][j] = LLINF;
    FOR(i,0,n) dp[i][0] = p[0][i];
    FOR(j,1,K) {
        FOR(i,j,n) {
            FOR(k,j,i+1) {
                dp[i][j] = min(dp[i][j], dp[k-1][j-1]+p[k][i]);
            }
        }
    }
    return dp[n-1][K-1];
}

signed main() {
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out","w",stdout);
    cin >> n >> K;
    FOR(i,0,n) cin >> a[i];
    int res = LLINF;
    FOR(i,0,n) res = min(res, solve(i));
    cout << res;
}