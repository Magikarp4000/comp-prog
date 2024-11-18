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

const int MAXN = 1e3+5;
int n,m,A,B,C,D;
int g[MAXN][MAXN], p[MAXN][MAXN];
PII row[MAXN][MAXN];
pair<int,PII> w[MAXN][MAXN];

signed main() {
    freopen("pyramid.in","r",stdin);
    freopen("pyramid.out","w",stdout);
    OPTM;
    cin >> m >> n >> A >> B >> C >> D;
    FOR(i,0,n) {
        FOR(j,0,m) cin >> g[i][j];
    }
    FOR(i,1,n+1) {
        FOR(j,1,m+1) {
            p[i][j] = g[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }
    int A1 = A-2, B1 = B-2;
    FOR(i,D-1,n) {
        deque<PII> dq;
        FOR(j,C-1,m) {
            int val = p[i+1][j+1]-p[i+1-D][j+1]-p[i+1][j+1-C]+p[i+1-D][j+1-C];
            if (!dq.empty() && dq.front().S-C+1 <= j-A1) dq.pop_front();
            while (!dq.empty() && dq.back().F >= val) dq.pop_back();
            dq.push_back({val,j});
            row[i][j] = dq.front();
        }
    }
    FOR(j,C-1,m) {
        deque<PII> dq;
        FOR(i,D-1,n) {
            int val = row[i][j].F;
            if (!dq.empty() && dq.front().S-D+1 <= i-B1) dq.pop_front();
            while (!dq.empty() && dq.back().F >= val) dq.pop_back();
            dq.push_back({val,i});
            w[i][j] = {dq.front().F, {row[dq.front().S][j].S, dq.front().S}};
        }
    }
    int resv = -INF;
    pair<PII,PII> res;
    FOR(i,B-1,n) {
        FOR(j,A-1,m) {
            int area = p[i+1][j+1]-p[i+1-B][j+1]-p[i+1][j+1-A]+p[i+1-B][j+1-A]-w[i-1][j-1].F;
            if (area > resv) {
                resv = area;
                res = {{j-A+2,i-B+2}, {w[i-1][j-1].S.F-C+2, w[i-1][j-1].S.S-D+2}};
            }
        }
    }
    cout << res.F.F << " " << res.F.S << ln << res.S.F << " " << res.S.S;
}