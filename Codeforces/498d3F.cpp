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

const int MAXN = 21;
int n,m,k;
int g[MAXN][MAXN];
vector<int> v[MAXN][MAXN];

signed main() {
    cin >> n >> m >> k;
    FOR(i,0,n) FOR(j,0,m) cin >> g[i][j];
    int h = (n+m-1)/2;
    FOR(s,0,1<<h) {
        int x = 0, y = 0;
        int cur = g[y][x];
        bool ok = 1;
        FOR(j,0,h) {
            if (s&(1<<j)) {
                if (y+1 >= n) {
                    ok = 0;
                    break;
                }
                y++;
            }
            else {
                if (x+1 >= m) {
                    ok = 0;
                    break;
                }
                x++;
            }
            cur ^= g[y][x];
        }
        v[y][x].PB(cur);
    }
    FOR(i,0,n) FOR(j,0,m) sort(ALL(v[i][j]));
    int res = 0;
    FOR(s,0,1<<(n+m-2-h)) {
        int x = m-1, y = n-1;
        int cur = g[y][x];
        bool ok = 1;
        FOR(j,0,n+m-2-h) {
            if (s&(1<<j)) {
                if (y-1 < 0) {
                    ok = 0;
                    break;
                }
                y--;
            }
            else {
                if (x-1 < 0) {
                    ok = 0;
                    break;
                }
                x--;
            }
            cur ^= g[y][x];
        }
        if (!ok) continue;
        cur ^= g[y][x];
        auto it = upper_bound(ALL(v[y][x]),k^cur);
        auto it1 = lower_bound(ALL(v[y][x]),k^cur);
        res += max(0LL,it-it1);
    }
    cout << res;
}