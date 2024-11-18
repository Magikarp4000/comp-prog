#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(5e18+7)
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

const int MAXN = 20;

int x,y,res;
int dp[MAXN][MAXN][2];
vector<int> dgx,dgy;

int solve(vector<int> num, int val) {
    int n = num.size();
    FOR(i,0,MAXN) {
        FOR(j,0,MAXN) {
            FOR(k,0,2) {
                dp[i][j][k] = 0LL;
            }
        }
    }
    dp[n][0][0] = dp[n][0][1] = 1LL;
    FORR(i,n-1,-1) {
        FOR(j,0,n) {
            dp[i][j][0] = ((dp[i+1][j][0]*9LL)%INF+dp[i+1][j-1][0])%INF;
            if (num[i] < val) {
                dp[i][j][1] = ((dp[i+1][j][0]*num[i])%INF+dp[i+1][j][1])%INF;
            }
            else if (num[i] == val) {
                if ()
                dp[i][j][1] = ((dp[i+1][j][0]*num[i])%INF+dp[i+1][j-1][1])%INF;
            }
            else {
                dp[i][j][1] = ((dp[i+1][j][0]*(num[i]-1))%INF+dp[i+1][j-1][0]+dp[i+1][j][1])%INF;
            }
        }
    }
    int ans = 0;
    FOR(j,(n+1)/2,n) ans = (ans+dp[0][j][1])%INF;
    return ans;
}

int calc(vector<int> num) {
    int ans = 0;
    FOR(i,0,10) ans = (ans+solve(num,i))%INF;
    return ans;
}

signed main() {
    // freopen("odometer.in","r",stdin);
    // freopen("odometer.out","w",stdout);
    cin >> x >> y;
    x--;
    while (x) {
        dgx.PB(x%10LL);
        x /= 10LL;
    }
    while (y) {
        dgy.PB(y%10LL);
        y /= 10LL;
    }
    reverse(ALL(dgx));
    reverse(ALL(dgy));
    int res = calc(dgy)-calc(dgx);
    cout << res;
}