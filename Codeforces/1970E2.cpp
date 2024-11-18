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

const int MAXN = 1e2+5;
int n,m;
int s[MAXN], l[MAXN], a[MAXN][MAXN], b[MAXN][MAXN], tmp[MAXN][MAXN];

void matmul(int m1[MAXN][MAXN], int m2[MAXN][MAXN]) {
    FOR(i,0,n) FOR(j,0,n) tmp[i][j] = 0;
    FOR(i,0,n) {
        FOR(j,0,n) {
            FOR(k,0,n) tmp[i][j] = (tmp[i][j]+m1[i][k]*m2[k][j])%INF;
        }
    }
    FOR(i,0,n) FOR(j,0,n) m1[i][j] = tmp[i][j];
}

void matexp(int t) {
    FOR(i,0,n) FOR(j,0,n) a[i][j] = (i==j);
    while (t) {
        if (t&1) matmul(a,b);
        matmul(b,b);
        t >>= 1;
    }
}

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) cin >> s[i];
    FOR(i,0,n) cin >> l[i];
    FOR(i,0,n) {
        FOR(j,0,n) b[i][j] = (s[i]*s[j]+s[i]*l[j]+l[i]*s[j])%INF;
    }
    matexp(m);
    int res = 0LL;
    FOR(i,0,n) res = (res+a[i][0])%INF;
    cout << res << ln;
}