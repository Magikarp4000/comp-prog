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

const int MAXN = 1e5+1;
int n,m;
vector<PLL> v[MAXN];
ll dp[MAXN][4];
bool z[MAXN];

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,m) {
        ll a,b,w;
        cin >> a >> b >> w;
        v[a].PB({b,w});
    }
    FOR(i,2,n+1) {
        dp[i][0] = LLINF;
        dp[i][2] = LLINF;
        dp[i][3] = -LLINF;
    }
    dp[1][1] = 1;
    PQ<pair<ll,ll>> pq;
    pq.push({0,1});
    while (!pq.empty()) {
        ll s = pq.top().S;
        pq.pop();
        FORX(u,v[s]) {
            if (dp[s][0]+u.S < dp[u.F][0]) {
                dp[u.F][0] = dp[s][0]+u.S;
                pq.push({-dp[u.F][0], u.F});
            }
        }
    }
    pq.push({0,1});
    while (!pq.empty()) {
        ll dist = -pq.top().F, s = pq.top().S;
        pq.pop();
        if (z[s]) continue;
        z[s] = 1;
        FORX(u,v[s]) {
            if (dp[s][0]+u.S == dp[u.F][0]) {
                pq.push({-dp[u.F][0], u.F});
                dp[u.F][1] = (dp[u.F][1]+dp[s][1])%INF;
                dp[u.F][2] = min(dp[u.F][2], dp[s][2]+1);
                dp[u.F][3] = max(dp[u.F][3], dp[s][3]+1);
            }
        }
    }
    FOR(j,0,4) cout << dp[n][j] << ' ';
}