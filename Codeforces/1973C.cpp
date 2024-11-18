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

const int MAXN = 1e5+5;
int n;
int p[MAXN];

void solve() {
    cin >> n;
    FOR(i,0,n) cin >> p[i];
    vector<int> v(n,0);
    int big = -1;
    FOR(i,0,n) if (p[i] == n) big = i;
    FOR(i,0,n) if (i == 0 || i == n || i%2 != big%2) v[i] = n-p[i];
    set<int> s;
    FOR(i,1,n+1) s.insert(i);
    FOR(i,0,n) if (v[i]) s.erase(v[i]);
    FOR(i,0,n) {
        if (!v[i]) {
            int x = *s.lower_bound(n+1-p[i]);
            v[i] = x;
            s.erase(x);
        }
    }
    FOR(i,0,n) cout << v[i] << " ";
    cout << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}