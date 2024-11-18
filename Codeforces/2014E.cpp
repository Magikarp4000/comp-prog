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
const ll LLINF = 2e18+1;
#define int long long

const int MAXN = 4e5+5;
int n,m,h;
int a[MAXN], d[MAXN][2], d1[MAXN][2];
vector<PII> v[MAXN];

void reset() {
    FOR(i,0,n+1) {
        a[i] = 0;
        v[i].clear();
        FOR(j,0,2) d[i][j] = d1[i][j] = LLINF;
    }
}

int solve() {
    cin >> n >> m >> h;
    reset();
    FOR(i,0,h) {
        int x; cin >> x;
        a[x] = 1;
    }
    FOR(i,0,m) {
        int x,y,w; cin >> x >> y >> w;
        v[x].PB({y,w}); v[y].PB({x,w});
    }
    PQ<pair<int,PII>> pq;
    pq.push({0,{1,a[1]}});
    d[1][a[1]] = 0;
    while (!pq.empty()) {
        int wi = pq.top().F, s = pq.top().S.F, has = pq.top().S.S;
        pq.pop();
        if (-wi > d[s][has]) continue;
        FORX(u,v[s]) {
            int tgt = has || a[u.F];
            int w = has ? u.S/2 : u.S;
            if (d[s][has]+w < d[u.F][tgt]) {
                d[u.F][tgt] = d[s][has]+w;
                pq.push({-d[u.F][tgt], {u.F, tgt}});
            }
        }
    }
    pq.push({0,{n,a[n]}});
    d1[n][a[n]] = 0;
    while (!pq.empty()) {
        int wi = pq.top().F, s = pq.top().S.F, has = pq.top().S.S;
        pq.pop();
        if (-wi > d1[s][has]) continue;
        FORX(u,v[s]) {
            int tgt = has || a[u.F];
            int w = has ? u.S/2 : u.S;
            if (d1[s][has]+w < d1[u.F][tgt]) {
                d1[u.F][tgt] = d1[s][has]+w;
                pq.push({-d1[u.F][tgt], {u.F, tgt}});
            }
        }
    }
    int res = LLINF;
    FOR(i,1,n+1) {
        FOR(j,0,2) FOR(k,0,2) res = min(res, max(d[i][j], d1[i][k]));
    }
    return (res == LLINF ? -1 : res);
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        cout << solve() << ln;
    }
}