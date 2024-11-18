#include "quality.h"
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

const int MAXN = 3e3+1;
int n,m,h,w,med;
int g[MAXN][MAXN], p[MAXN][MAXN];

bool check(int x) {
    FOR(i,1,n+1) FOR(j,1,m+1) p[i][j] = 0;
    FOR(i,1,n+1) {
        FOR(j,1,m+1) {
            int c = g[i-1][j-1] < x;
            p[i][j] = p[i][j-1]+p[i-1][j]-p[i-1][j-1]+c;
        }
    }
    FOR(i,h,n+1) {
        FOR(j,w,m+1) {
            int sum = p[i][j]-p[i-h][j]-p[i][j-w]+p[i-h][j-w];
            if (sum > med) return 1;
        }
    }
    return 0;
}

int rectangle(int R, int C, int H, int W, int G[3001][3001]) {
    n = R; m = C; h = H, w = W;
    FOR(i,0,n) FOR(j,0,m) g[i][j] = G[i][j];
    med = h*w/2;
    int l = 1, r = n*m;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) r = mid-1;
        else l = mid;
    }
    return l;
}
