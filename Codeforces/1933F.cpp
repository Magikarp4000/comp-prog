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

const int MAXN = 1e3+5;
int n,m;
bool g[MAXN][MAXN];
int d[MAXN][MAXN];

void solve() {
    cin >> n >> m;
    FOR(i,0,n) FOR(j,0,m) cin >> g[i][j];
    FOR(i,0,n) FOR(j,0,m) d[i][j] = INF;
    queue<PII> q;
    q.push({0,0});
    d[0][0] = 0;
    while (!q.empty()) {
        int y = q.front().F, x = q.front().S;
        q.pop();
        if (x+1 < m && !g[(y+1)%n][x+1] && d[y][x]+1 < d[(y+1)%n][x+1]) {
            d[(y+1)%n][x+1] = d[y][x]+1;
            q.push({(y+1)%n,x+1});
        }
        if (!g[(y+1)%n][x] && !g[(y+2)%n][x] && d[y][x]+1 <d[(y+2)%n][x]) {
            d[(y+2)%n][x] = d[y][x]+1;
            q.push({(y+2)%n,x});
        }
    }
    int res = INF;
    FOR(i,0,n) {
        if (d[i][m-1] == INF) continue;
        int pos = ((i-d[i][m-1])%n+n)%n;
        res = min(res, min(n-1-pos, pos+1)+d[i][m-1]);
    }
    cout << (res == INF ? -1 : res) << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}