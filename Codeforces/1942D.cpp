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

const int MAXN = 1e3+5, MAXK = 5e3+5;
int n,k;
int a[MAXN][MAXN];
vector<int> dp[MAXN];

void solve() {
    cin >> n >> k;
    FOR(i,0,n+2) dp[i].clear();
    FOR(i,2,n+2) {
        FOR(j,i,n+2) cin >> a[i][j];
    }
    dp[0].PB(0), dp[1].PB(0);
    FOR(i,2,n+2) {
        PQ<PII> pq;
        FOR(j,0,i) pq.push({dp[j][0]+a[j+2][i], j});
        vector<int> v(n+2,1), curv;
        int cnt = 0;
        while (!pq.empty() && cnt < k) {
            int val = pq.top().F, idx = pq.top().S;
            pq.pop();
            curv.PB(val);
            cnt++;
            if (v[idx] < dp[idx].size()) pq.push({dp[idx][v[idx]++]+a[idx+2][i], idx});
        }
        dp[i] = curv;
    }
    FORX(u,dp[n+1]) cout << u << " ";
    cout << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}