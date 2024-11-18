#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+7)
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

const int MAXN = 1e5+5;
int n,m;
int s[MAXN], l[MAXN], t[MAXN];
int a[MAXN][2], b[2][2], c[2][2], tmp[2][2];

void matmul(int m1[2][2], int m2[2][2]) {
    FOR(i,0,2) FOR(j,0,2) tmp[i][j] = 0;
    FOR(i,0,2) {
        FOR(j,0,2) {
            FOR(k,0,2) tmp[i][j] = (tmp[i][j]%INF+((m1[i][k]%INF)*(m2[k][j]%INF))%INF)%INF;
        }
    }
    FOR(i,0,2) FOR(j,0,2) m1[i][j] = tmp[i][j];
}

void matexp(int t) {
    FOR(i,0,2) FOR(j,0,2) b[i][j] = (i==j);
    while (t) {
        if (t&1) matmul(b,c);
        matmul(c,c);
        t >>= 1;
    }
}

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) cin >> s[i];
    FOR(i,0,n) cin >> l[i];
    FOR(i,0,n) t[i] = s[i]+l[i];
    FOR(i,0,n) {
        c[0][0] += (t[i]*t[i])%INF;
        c[0][1] += (t[i]*l[i])%INF;
        c[1][0] += (-l[i]*t[i]+INF)%INF;
        c[1][1] += (-l[i]*l[i]+INF)%INF;
    }
    matexp(m-1);
    FOR(i,0,n) {
        FOR(j,0,2) {
            a[i][j] = ((t[i]*b[0][j])%INF+(l[i]*b[1][j])%INF)%INF;
        }
    }
    int res = 0;
    FOR(i,0,n) res = (res+(a[i][0]*t[0])%INF-(a[i][1]*l[0])%INF+INF)%INF;
    cout << res << ln;
}