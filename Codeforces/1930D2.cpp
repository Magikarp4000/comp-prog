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

const int MAXN = 1e6+5;
int n;
string s;
int r[MAXN], l[MAXN], a[MAXN], b[MAXN];
bool z[MAXN];

void solve() {
    cin >> n >> s;
    FOR(i,0,n+5) {
        r[i] = n;
        a[i] = z[i] = 0;
        b[i] = s[i]-'0';
    }
    FORR(i,n-1,-1) {
        if (s[i] == '0') r[i] = r[i+1];
        else r[i] = i;
    }
    FOR(i,0,n) {
        if (z[i]) continue;
        if (s[i] == '0') {
            b[r[i]]++;
            continue;
        }
        int j = i, cnt = 0, cur = 0;
        vector<int> v;
        while (j < n && !z[j]) {
            z[j] = 1;
            v.PB(j);
            j = r[j+3];
        }
        if (j < n && z[j]) v.PB(j);
        else v.PB(n);
        int vn = v.size();
        FORR(k,vn-2,-1) a[v[k]] = a[v[k+1]]+n-v[k];
    }
    int res = 0;
    FOR(i,0,n) res += a[i]*b[i];
    cout << res << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}