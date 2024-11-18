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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
const int MAXN = 8e2+1;
int n,s;
string g[MAXN];
PII sta, en;
vector<PII> h;
int hn;
int mz[MAXN][MAXN], hz[MAXN][MAXN];
int md[MAXN][MAXN], hd[MAXN][MAXN];

bool check(int cur) {
    FOR(i,0,n) {
        FOR(j,0,n) {
            mz[i][j] = 0;
            hz[i][j] = 0;
            md[i][j] = INF;
            hd[i][j] = INF;
        }
    }
    queue<PII> q;
    FOR(i,0,hn) {
        q.push(h[i]);
        hd[h[i].S][h[i].F] = 0;
    }
    while (!q.empty()) {
        int x = q.front().F, y = q.front().S;
        q.pop();
        if (hz[y][x]) continue;
        hz[y][x] = 1;
        FOR(i,0,4) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
            if (g[ny][nx] == 'T' || g[ny][nx] == 'D') continue;
            if (hd[y][x]+1 < hd[ny][nx]) {
                hd[ny][nx] = hd[y][x]+1;
                q.push({nx,ny});
            }
        }
    }
    if (hd[sta.S][sta.F] <= cur) return 0;
    md[sta.S][sta.F] = 0;
    q.push(sta);
    while (!q.empty()) {
        int x = q.front().F, y = q.front().S;
        q.pop();
        if (mz[y][x]) continue;
        mz[y][x] = 1;
        FOR(i,0,4) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
            if (g[ny][nx] == 'T') continue;
            if (md[y][x]+1 < md[ny][nx] && hd[ny][nx]-cur > (md[y][x]+1)/s) {
                md[ny][nx] = md[y][x]+1;
                q.push({nx,ny});
            }
            else if (md[y][x]+1 < md[ny][nx] && hd[ny][nx]-cur == (md[y][x]+1)/s) {
                md[ny][nx] = md[y][x]+1;
                mz[ny][nx] = 1;
            }
        }
    }
    if (mz[en.S][en.F]) return 1;
    return 0;
}

signed main() {
    OPTM;
    cin >> n >> s;
    FOR(i,0,n) cin >> g[i];
    FOR(i,0,n) {
        FOR(j,0,n) {
            if (g[i][j] == 'M') sta = {j,i};
            if (g[i][j] == 'D') en = {j,i};
            if (g[i][j] == 'H') h.PB({j,i});
        }
    }
    hn = h.size();
    int l = 0, r = 1e7+1;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    if (!check(0)) cout << -1;
    else cout << l << ln;;
}