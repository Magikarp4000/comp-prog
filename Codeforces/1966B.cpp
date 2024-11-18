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

const int MAXN = 505;
int n,m;
string g[MAXN];

bool check(char c) {
    bool ok=0,ok1=0,ok2=0,ok3=0;
    FOR(i,0,n) {
        if (g[i][0] == c) ok = 1;
        if (g[i][m-1] == c) ok1 = 1;
    }
    FOR(j,0,m) {
        if (g[0][j] == c) ok2 = 1;
        if (g[n-1][j] == c) ok3 = 1;
    }
    return ok&&ok1&&ok2&&ok3;
}

void solve() {
    cin >> n >> m;
    FOR(i,0,n) cin >> g[i];
    if (check('W') || check('B')) cout << "YES";
    else cout << "NO";
    cout << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}