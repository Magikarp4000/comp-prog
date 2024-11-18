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
#define int long long

const int MAXA = 3e5, MAXN = 1e6+5;
int n;
bool unprime[MAXA+1];
vector<int> p;
US<int> v[30000];

void solve() {
    cin >> n;
    int m = 1LL;
    while (1) {
        if ((m%2LL) && m*(m+1LL)/2LL+1LL >= n) break;
        else if (!(m%2LL) && m*m/2LL+2LL >= n) break;
        m++;
    }
    FOR(i,0,m) v[i].clear();
    FOR(i,0,m) {
        FOR(j,i,m) {
            if (!(m%2) && j == (i+m/2)%m) continue;
            v[i].insert(j), v[j].insert(i);
        }
    }
    if (!(m%2)) v[0].insert(m/2), v[m/2].insert(0);
    vector<int> path;
    stack<int> st;
    st.push(-1);
    int cur = 0;
    while (!st.empty()) {
        if (v[cur].empty()) {
            path.PB(cur);
            cur = st.top();
            st.pop();
        }
        else {
            int u = *(v[cur].begin());
            v[cur].erase(u);
            if (u != cur) v[u].erase(cur);
            st.push(cur);
            cur = u;
        }
    }
    FOR(i,0,n) cout << p[path[i]] << " ";
    cout << ln;
}

signed main() {
    OPTM;
    FOR(i,2,MAXA+1) {
        for (int j = i+i; j <= MAXA; j += i) unprime[j] = 1;
    }
    FOR(i,1,MAXA+1) if (!unprime[i]) p.PB(i);
    int T; cin >> T;
    while (T--) solve();
}