#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int MAXN = 3e3+5;
int n,K;
int a[MAXN], pu[MAXN][MAXN], pd[MAXN][MAXN], dp[MAXN][MAXN];

void solve(int i, int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l+r)/2;
    int optmid = 0;
    dp[i][mid] = LLINF;
    FOR(k,optl,min(mid,optr+1)) {
        int C = pu[k][(k+mid)/2] + pd[mid][(k+mid)/2+1];
        if (dp[i-1][k]+C < dp[i][mid]) {
            dp[i][mid] = dp[i-1][k]+C;
            optmid = k;
        }
    }
    solve(i,l,mid-1,optl,optmid);
    solve(i,mid+1,r,optmid,optr);
}

signed main() {
    OPTM;
    cin >> n >> K;
    FOR(i,0,n) cin >> a[i];

    FOR(i,0,n) {
        pu[i][i] = pd[i][i] = 0;
        FOR(j,i+1,n) pu[i][j] = pu[i][j-1] + a[j]*(j-i);
        FORR(j,i-1,-1) pd[i][j] = pd[i][j+1] + a[j]*(i-j);
    }

    FOR(j,0,n) dp[1][j] = pd[j][0];
    FOR(i,2,K+1) solve(i,0,n-1,0,n-1);

    int res = LLINF;
    FOR(j,0,n) res = min(res, dp[K][j]  +   pu[j][n-1]);
    cout << res;
}