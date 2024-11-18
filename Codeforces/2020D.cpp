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

const int MAXN = 2e5+5;
int p[MAXN], sz[MAXN];
vector<PII> z[11][11];

int finds(int s) {
    if (p[s] != s) p[s] = finds(p[s]);
    return p[s];
}

void unite(int a, int b) {
    a = finds(a);
    b = finds(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

void reset(int n) {
    FOR(i,0,n+1) {
        p[i] = i;
        sz[i] = 1;
    }
    FOR(i,0,11) FOR(j,0,11) z[i][j].clear();
}

int solve() {
    int n,m; cin >> n >> m;
    reset(n);
    FOR(i,0,m) {
        int a,d,k; cin >> a >> d >> k;
        z[d][(a%d)+1].PB({a, a+k*d});
    }
    FOR(i,1,11) {
        FOR(j,1,i+1) {
            sort(ALL(z[i][j]));
            int l = -1, r = -2;
            FORX(u,z[i][j]) {
                if (u.F <= r) r = max(r, u.S);
                else {
                    for (int y = l; y <= r; y += i) {
                        unite(l, y);
                    }
                    l = u.F;
                    r = u.S;
                }
            }
            for (int y = l; y <= r; y += i) {
                unite(l, y);
            }
        }
    }
    int res = 0;
    US<int> vis;
    FOR(i,1,n+1) {
        // cout << finds(i) << " ";
        vis.insert(finds(i));
    }
    return vis.size();
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        cout << solve() << ln;
    }
}