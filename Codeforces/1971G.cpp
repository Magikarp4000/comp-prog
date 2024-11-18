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

const int MAXN = 2e5+5;
int n;
int a[MAXN];
UM<int,set<int,greater<int>>> mp;

void solve() {
    cin >> n;
    mp.clear();
    FOR(i,0,n) cin >> a[i], mp[a[i]].insert(i);
    FOR(i,0,n) {
        vector<int> v;
        FOR(j,1,4) {
            int x = a[i]^j;
            if (mp.count(x) && !mp[x].empty() && *(mp[x].begin()) > i && x < a[i]) v.PB(x);
        }
        if (v.empty()) continue;
        int x = *min_element(ALL(v)), orig = a[i], idx = *(mp[x].begin());
        swap(a[i], a[idx]);
        mp[x].erase(idx);
        mp[orig].insert(idx);
    }
    FOR(i,0,n) cout << a[i] << " ";
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        solve();
        cout << ln;
    }
}