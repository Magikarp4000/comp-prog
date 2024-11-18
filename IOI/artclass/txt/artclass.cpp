#include "artclass.h"
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
const int VAR = 15;
const int LINEVAR = 50;
const int EPS = 10;
const int EPS1 = 10;

struct Coord {
    PII tp,ri,bt,le;
};

const int MAXN = 5e2+5;
int h, w, r[MAXN][MAXN], g[MAXN][MAXN], b[MAXN][MAXN], z[MAXN][MAXN];
vector<Coord> v;
vector<int> cnts;

bool same(int x1, int y1, int x2, int y2) {
    if (abs(r[y1][x1]-r[y2][x2]) > VAR) return 0;
    if (abs(g[y1][x1]-g[y2][x2]) > VAR) return 0;
    if (abs(b[y1][x1]-b[y2][x2]) > VAR) return 0;
    return 1;
    // int diff = abs(r[y1][x1]-r[y2][x2])+abs(g[y1][x1]-g[y2][x2])+abs(b[y1][x1]-b[y2][x2]);
}

bool black(int x, int y) {
    if (r[y][x] > LINEVAR) return 0;
    if (g[y][x] > LINEVAR) return 0;
    if (b[y][x] > LINEVAR) return 0;
    return 1;
}

bool green(int x, int y) {
    return (g[y][x] > r[y][x] && g[y][x] > b[y][x]);
}

void bfs(int sx, int sy, int idx) {
    queue<PII> q;
    q.push({sx,sy});
    Coord cur = {{INF,INF},{-INF,INF},{-INF,-INF},{INF,-INF}};
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().F, y = q.front().S;
        q.pop();
        z[y][x] = idx;
        cnt++;
        if (y < cur.tp.S || (y == cur.tp.S && x < cur.tp.F)) cur.tp = {x,y};
        if (x > cur.ri.F || (x == cur.ri.F && y < cur.ri.S)) cur.ri = {x,y};
        if (y > cur.bt.S || (y == cur.bt.S && x > cur.bt.F)) cur.bt = {x,y};
        if (x < cur.le.F || (x == cur.le.F && y > cur.le.S)) cur.le = {x,y};
        FOR(i,0,4) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (z[ny][nx]) continue;
            if (same(x,y,nx,ny)) {
                z[ny][nx] = idx;
                q.push({nx,ny});
            }
        }
    }
    // FOR(i,0,h) {
    //     FOR(j,0,w) {
    //         if (z[i][j]) {
    //             cur.tp = {j,i};
    //             break;
    //         }
    //     }
    // }
    // FORR(j,w-1,-1) {
    //     FOR(i,0,h) {
    //         if (z[i][j]) {
    //             cur.ri = {j,i};
    //             break;
    //         }
    //     }
    // }
    // FORR(i,h-1,-1) {
    //     FORR(j,w-1,-1) {
    //         if (z[i][j]) {
    //             cur.bt = {j,i};
    //             break;
    //         }
    //     }
    // }
    // FOR(j,0,w) {
    //     FORR(i,h,-1) {
    //         if (z[i][j]) {
    //             cur.le = {j,i};
    //             break;
    //         }
    //     }
    // }
    v.PB(cur);
    cnts.PB(cnt);
    // int cnt = 0;
    // FOR(i,0,h) FOR(j,0,w) cnt += z[i][j] > 0;
    // cnts.PB(cnt);
}

int style(int H, int W, int R[500][500], int G[500][500], int B[500][500]) {
    h = H, w = W;
    FOR(i,0,h) FOR(j,0,w) r[i][j] = R[i][j], g[i][j] = G[i][j], b[i][j] = B[i][j];
    int idx = 1;
    FOR(i,0,h) {
        FOR(j,0,w) {
            if (z[i][j]) continue;
            // if (r[i][j]+g[i][j]+b[i][j] <= VAR) continue;
            bfs(j,i,idx++);
        }
    }
    int line = 0;
    bool prev = 0;
    FOR(i,0,h) {
        int bad = 0;
        FOR(j,0,w) bad += !black(j,i);
        if (bad <= 15) {
            if (!prev) line++;
            prev = 1;
        }
        else prev = 0;
    }
    prev = 0;
    FOR(j,0,w) {
        int bad = 0;
        FOR(i,0,h) bad += !black(j,i);
        if (bad <= 15) {
            if (!prev) line++;
            prev = 1;
        }
        else prev = 0;
    }
    // cout << "line: " << line << ln;
    // if (line >= 10) return 1;
    int vn = v.size(), num = 0;
    FOR(i,0,vn) if (cnts[i] >= 30) num++;
    if (num >= 6 && line >= 7) return 1;
    int num1 = 0;
    FOR(i,0,vn) if (cnts[i] >= h*w/5) num1++;
    if (num1 >= num*3/5) return 4;
    // FOR(i,0,vn) {
    //     if (cnts[i] <= 20) continue;
    //     Coord u = v[i];
    //     // cout << u.tp.F << " " << u.tp.S << " ";
    //     // cout << u.ri.F << " " << u.ri.S << " ";
    //     // cout << u.bt.F << " " << u.bt.S << " ";
    //     // cout << u.le.F << " " << u.le.S << ln;
    //     // cout << cnts[i] << ln;
    //     int val = (u.le.S-u.tp.S)*(u.ri.F-u.bt.F);
    //     int val1 = (u.bt.S-u.ri.S)*(u.tp.F-u.le.F);
    //     if (abs(val-val1) <= EPS) num++;
    // }
    // if (num >= 20) return 1;
    FOR(k,0,vn) {
        Coord u = v[k];
        int area = (u.bt.S-u.tp.S)*(u.ri.F-u.le.F);
        // cout << "area: " << area << ln;
        // if (area >= cnts[k]*9/10 && area <= cnts[k]*11/10) return 4;
        // continue;
        if (abs(u.ri.S-u.tp.S) <= EPS1
            && abs(u.ri.F-u.bt.F) <= EPS1
            && abs(u.bt.S-u.le.S) <= EPS1
            && abs(u.tp.F-u.le.F) <= EPS1
        ) {
            if (area <= h*w/15) continue;
            int bad = 0;
            FOR(i,u.tp.S,u.bt.S+1) {
                FOR(j,u.le.F,u.ri.F+1) {
                    if (z[i][j] != k+1) {
                        bad++;
                    }
                }
            }
            if (bad <= 15) return 4; 
        }
    }
    int gre = 0;
    FOR(i,0,h) FOR(j,0,w) gre += green(j,i);
    if (gre >= h*w*0.25) return 2;
    // int red = 0, gre = 0, blu = 0;
    // FOR(i,0,h) FOR(j,0,w) red += r[i][j], gre += g[i][j], blu += b[i][j];
    // if (gre > red+0 && gre > blu+0) return 2;
    // FORX(u,cnts) if (u >= h*w/4) return 4;
    return 3;
}
