#include "wombats.h"
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

const int MAXN = 5e3+5, MAXM = 1e2+5;
int r,c,h[MAXN][MAXM],v[MAXN][MAXM];
int p[MAXN][MAXM], d[MAXN][MAXM][MAXM], dp[MAXN][MAXM][MAXM];

void calcdist(int row) {
    FOR(i,0,c) FOR(j,0,c) d[row][i][j] = INF;
    FOR(i,0,c) {
        FOR(j,0,c) {
            FOR(k,0,c) {
                d[row][i][j] = min(d[row][i][j], abs(p[row][k]-p[row][i])+abs(p[row+1][k]-p[row+1][j])+v[row][k]);
            }
        }
    }
}

void calcdp() {
    FORR(row,r-2,-1) {
        FOR(i,0,c) FOR(j,0,c) dp[row][i][j] = INF;
        FOR(i,0,c) {
            FOR(j,0,c) {
                FOR(k,0,c) {
                    dp[row][i][j] = min(dp[row][i][j], d[row][i][k]+dp[row+1][k][j]);
                }
            }
        }
    }
}

void init(int R, int C, int H[5000][200], int V[5000][200]) {
    r = R, c = C;
    FOR(i,0,r) FOR(j,0,c) h[i][j] = H[i][j], v[i][j] = V[i][j];
    FOR(i,0,r) FOR(j,1,c) p[i][j] = p[i][j-1]+h[i][j-1];
    FOR(row,0,r) FOR(i,0,c) FOR(j,0,c) d[row][i][j] = dp[row][i][j] = INF;
    FOR(i,0,c) FOR(j,0,c) dp[r-1][i][j] = abs(p[r-1][i]-p[r-1][j]);
    FOR(row,0,r-1) calcdist(row);
    calcdp();
}

void changeH(int P, int Q, int W) {
    h[P][Q] = W;
    FOR(j,1,c) p[P][j] = p[P][j-1]+h[P][j-1];
    if (P == r-1) {
        FOR(i,0,c) FOR(j,0,c) dp[r-1][i][j] = abs(p[r-1][i]-p[r-1][j]);
    }
    if (P > 0) calcdist(P-1);
    if (P < r-1) calcdist(P);
    calcdp();
}

void changeV(int P, int Q, int W) {
    v[P][Q] = W;
    calcdist(P);
    calcdp();
}

int escape(int V1, int V2) {
    // FOR(i,0,r) {
    //     FOR(j,1,c) cout << p[i][j] << " ";
    //     cout << ln;
    // }
    // FOR(i,0,c) {
    //     FOR(j,0,c) cout << d[1][i][j] << " ";
    //     cout << ln;
    // }
    return dp[0][V1][V2];
}
