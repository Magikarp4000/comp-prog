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
#define int long long

const int MAXN = 2e3+5;
int n,m;
int r[MAXN], w[MAXN], pos[MAXN];

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,1,n+1) cin >> r[i];
    set<int> s;
    queue<int> q;
    FOR(i,1,n+1) s.insert(i);
    FOR(i,1,m+1) cin >> w[i];
    int res = 0;
    FOR(i,0,2*m) {
        int x; cin >> x;
        if (x >= 0) q.push(x);
        else s.insert(pos[-x]), pos[-x] = 0;
        while (!q.empty() && !s.empty()) {
            int cur = *s.begin(), idx = q.front();
            s.erase(cur), q.pop();
            res += r[cur]*w[idx];
            pos[idx] = cur;
        }
    }
    cout << res;
}