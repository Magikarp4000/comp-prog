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

const int MAXN = 21;
int n,m;
vector<int> r[MAXN];
ll dp[1<<MAXN][MAXN];

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,m) {
        int a,b; cin >> a >> b;
        r[b].PB(a);
    }
    dp[1][1] = 1;
    FOR(s,0,(1<<n)) {
        if (!(s&(1<<0))) continue;
        FOR(i,1,n+1) {
            if (!(s&(1<<(i-1)))) continue;
            FORX(u,r[i]) {
                if (s&(1<<(u-1))) dp[s][i] = (dp[s][i]+dp[s&~(1<<(i-1))][u])%INF;
            }
        }
    }
    cout << dp[(1<<n)-1][n];
}