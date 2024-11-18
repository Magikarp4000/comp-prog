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

const int MAXN = 1e3+5;
int n,K;
int a[MAXN], dp[MAXN][MAXN], p[MAXN][MAXN];

int bruh(int x, int rot) {
    return (x+rot >= n ? x+rot-n : x+rot);
}

void solve(int rot, int i, int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l+r)/2;
    int optmid = 0;
    dp[i][mid] = LLINF;
    int C = 0;
    FORR(k,mid-1,optr) C += a[bruh(k,rot)] * (mid-k);
    FORR(k,min(mid-1,optr),optl-1) {
        if (dp[i-1][k]+C < dp[i][mid]) {
            dp[i][mid] = dp[i-1][k]+C;
            optmid = k;
        }
        C += a[bruh(k,rot)] * (mid-k);
    }
    solve(rot,i,l,mid-1,optl,optmid);
    solve(rot,i,mid+1,r,optmid,optr);
}

signed main() {
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    OPTM;
    cin >> n >> K;
    FOR(i,0,n) cin >> a[i];
    reverse(a,a+n);
    int res = LLINF;
    FOR(i,0,n) {
        FORR(j,i-1,-1) p[i][j] += a[j]*(i-j);
    }
    FOR(rot,0,n) {
        FOR(j,0,n) dp[1][j] = LLINF;
        dp[1][0] = 0;
        FOR(i,2,K+1) solve(rot,i,0,n-1,0,n-1);
        int cur = 0;
        FORR(j,n,0) {
            if (j < n) cur += a[bruh(j,rot)]*(n-j);
            res = min(res, dp[K][j-1]+cur);
        }
    }
    cout << res;
}