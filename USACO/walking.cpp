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
#define int long long

const int MAXN = 2e5+5;
int n,q;
vector<int> rows,cols;
vector<PII> v;
US<int> cs;

bool check(int pos, int sx, int sy, bool initdir) {
    if (v[pos].S < sy || (initdir == 0 && v[pos].S == sy) || v[pos].F < sx) return 1;
    if (initdir == 0 && (pos == 0 || v[pos-1].S <= sy)) {
        if ((v[pos].S-sy)%2 == 0) return 1;
    }
    if (initdir == 1 && (pos == 0 || v[pos-1].F < sx)) {
        if ((v[pos].F-sx)%2 == 1) return 1;
    }
    return 0;
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) {
        char t; int pos;
        cin >> t >> pos;
        if (t == 'V') cols.PB(pos), cs.insert(pos);
        else rows.PB(pos); 
    }
    sort(ALL(rows));
    sort(ALL(cols));
    int rn = rows.size(), cn = cols.size();
    v.PB({-LLINF,-LLINF});
    int i = 0, j = 0, pi = 2, pj = 2;
    while (i < rn && j < cn) {
        while (i < rn && rows[i]%2LL == pi) i++;
        while (j < cn && cols[j]%2LL == pj) j++;
        if (i >= rn || j >= cn) break;
        v.PB({cols[j], rows[i]});
        pi = rows[i]%2LL, pj = cols[j]%2LL;
    }
    v.PB({LLINF,LLINF});
    int vn = v.size();
    FOR(i,0,vn) cout << v[i].F << " " << v[i].S << ln;
    exit(0);
    FOR(_,0,q) {
        int sx,sy,d; cin >> sx >> sy >> d;
        bool initdir = !cs.count(sx);
        if (sx > v.back().F || sy > v.back().S || (initdir == 0 && sy >= v.back().S)) {
            if (initdir == 1) cout << sx+d << " " << sy << ln;
            else cout << sx << " " << sy+d << ln;
            continue;
        }
        int l = 0, r = vn-1;
        while (l < r) {
            int mid = (l+r)/2LL;
            if (check(mid,sx,sy,initdir)) l = mid+1;
            else r = mid;
        }
        int sta = l;
        l = sta, r = vn-1;
        while (l < r) {
            int mid = (l+r)/2LL;
            if (v[mid].F-sx + v[mid].S-sy <= d) l = mid+1LL;
            else r = mid;
        }
        int cx = sx, cy = sy, nx = v[l].F, ny = v[l].S;
        if (l > sta && v[l-1].F-sx + v[l-1].S-sy <= d) {
            cx = v[l-1].F, cy = v[l-1].S;
        }
        int dir = (cx-sx + cy-sy)%2LL;
        if (cx-sx + cy-sy == 0LL) dir = initdir;
        if (dir == 1) {
            if (l == vn-1 || nx-sx + cy-sy > d) cout << sx+d-(cy-sy) << " " << cy << ln;
            else cout << nx << " " << sy+d-(nx-sx) << ln;
        }
        else {
            if (l == vn-1 || ny-sy + cx-sx > d) cout << cx << " " << sy+d-(cx-sx) << ln;
            else cout << sx+d-(ny-sy) << " " << ny << ln;
        }
    }
}