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

const int MAXN = 1e5+1;
int n,xl,yl,xb,yb;
UM<int,vector<int>> mx, my;
vector<int> v[MAXN*4], vx, vy;
UM<int,int> mpx, mpy;
int d[MAXN*4];
bool z[MAXN*4];

signed main() {
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    OPTM;
    cin >> n >> xl >> yl >> xb >> yb;
    mx[xl].PB(yl);
    my[yl].PB(xl);
    mx[xb].PB(yb);
    my[yb].PB(xb);
    vx.PB(xl);
    vx.PB(xb);
    vy.PB(yl);
    vy.PB(yb);
    FOR(i,0,n) {
        int x,y; cin >> x >> y;
        mx[x].PB(y);
        my[y].PB(x);
        vx.PB(x);
        vy.PB(y);
    }
    sort(ALL(vx)); sort(ALL(vy));
    unique(ALL(vx)); unique(ALL(vy));
    int xn = vx.size(), yn = vy.size();
    FOR(i,0,xn) mpx[vx[i]] = i;
    FOR(i,0,yn) mpy[vy[i]] = i+xn;
    FORX(u,mx) {
        FORX(w,u.S) v[mpx[u.F]].PB(mpy[w]);
    }
    FORX(u,my) {
        FORX(w,u.S) v[mpy[u.F]].PB(mpx[w]);
    }
    FOR(i,0,MAXN*2) d[i] = INF;
    int s1 = mpx[xl], s2 = mpy[yl];
    d[s1] = 0;
    d[s2] = 0;
    queue<int> q;
    q.push(s1);
    q.push(s2);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        if (z[s]) continue;
        z[s] = 1;
        FORX(u,v[s]) {
            if (d[s]+1 < d[u]) {
                d[u] = d[s]+1;
                q.push(u);
            }
        }
    }
    int e1 = mpx[xb], e2 = mpy[yb];
    if (min(d[e1],d[e2]) == INF) cout << -1;
    else cout << min(d[e1],d[e2]);
}