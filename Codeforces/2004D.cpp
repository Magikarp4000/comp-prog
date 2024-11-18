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

int n,q;
UM<string, set<int>> mp;
vector<string> v;

bool check(string s, string t) {
    return (s[0] == t[0] || s[0] == t[1] || s[1] == t[0] || s[1] == t[1]);
}

int calc(string s, int a, int b) {
    auto it = mp[s].lower_bound(a);
    int mi = INF;
    if (it != mp[s].end()) {
        int x = *it;
        mi = abs(a-x) + abs(x-b);
    }
    if (it != mp[s].begin()) {
        int x = *(--it);
        mi = min(mi, abs(a-x) + abs(x-b));
    }
    return mi;
}

void solve() {
    cin >> n >> q;
    mp.clear();
    v.clear();
    FOR(i,0,n) {
        string s; cin >> s;
        mp[s].insert(i);
        v.PB(s);
    }
    FOR(_,0,q) {
        int a,b; cin >> a >> b;
        a--, b--;
        if (check(v[a], v[b])) {
            cout << abs(a-b) << ln;
            continue;
        }
        int res = INF;
        FOR(i,0,2) {
            FOR(j,0,2) {
                string s = "";
                s.PB(min(v[a][i], v[b][j]));
                s.PB(max(v[a][i], v[b][j]));
                res = min(res, calc(s,a,b));
            }
        }
        cout << (res == INF ? -1 : res) << ln;
    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}