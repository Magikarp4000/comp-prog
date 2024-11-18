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
#define in(v,x) (v.find(x) != v.end())
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 5e2+1;
int n;
int a[MAXN], b[MAXN];

string solve() {
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) cin >> b[i];
    if (n%2 == 1 && a[n/2] != b[n/2]) return "No";
    vector<PII> va,vb;
    FOR(i,0,n/2) {
        PII pa = {min(a[i],a[n-i-1]), max(a[i],a[n-i-1])};
        PII pb = {min(b[i],b[n-i-1]), max(b[i],b[n-i-1])};
        va.PB(pa); vb.PB(pb);
    }
    sort(ALL(va));
    sort(ALL(vb));
    int vn = va.size();
    FOR(i,0,vn) if (va[i] != vb[i]) return "No";
    return "Yes";
}

signed main() {
    int t; cin >> t;
    while (t--) cout << solve() << ln;
}