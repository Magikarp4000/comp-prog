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

const int MAXN = 2e5+1;
int n;
int a[MAXN], dp[MAXN];

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n+1) dp[i] = INF;
    FOR(i,0,n) {
        int cur = lower_bound(dp,dp+n,a[i])-dp;
        dp[cur] = a[i];
    }
    int i = 0;
    while (i < n && dp[i] != INF) i++;
    cout << i;
}