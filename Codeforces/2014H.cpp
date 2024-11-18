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

const int MAXN = 2e5+5, MAXM = 1e6+5, SQRT = 420;
int n,q;
int a[MAXN], b[MAXM], res[MAXN], cnt;
vector<pair<PII,int>> qrs;
US<int> s;

void reset() {
    qrs.clear();
    cnt = 0;
    FOR(i,0,n+1) a[i] = res[i] = 0;
    for (auto u: s) b[u] = 0;
    s.clear();
}

bool cmp(const pair<PII,int>& x, const pair<PII,int>& y) {
    return (make_pair(x.F.F/SQRT, x.F.S) < make_pair(y.F.F/SQRT, y.F.S));
}

inline void add(int x) {
    b[a[x]]++;
    cnt += (b[a[x]]&1) ? 1 : -1;
}

inline void rem(int x) {
    b[a[x]]--;
    cnt += (b[a[x]]&1) ? 1 : -1;
}

void solve() {
    cin >> n >> q;
    reset();
    FOR(i,0,n) cin >> a[i], s.insert(a[i]);
    FOR(i,0,q) {
        int l,r; cin >> l >> r;
        l--; r--;
        qrs.PB({{l,r},i});
    }
    sort(ALL(qrs),cmp);
    int l = 0, r = -1;
    for (auto qry: qrs) {
        // cout << "qry: " << qry.F.F << " " << qry.F.S << ln;
        while (l > qry.F.F) l--, add(l);
        while (r < qry.F.S) r++, add(r);
        while (l < qry.F.F) rem(l), l++;
        while (r > qry.F.S) rem(r), r--;
        res[qry.S] = cnt;
    }
    FOR(i,0,q) cout << (res[i] == 0 ? "YES" : "NO") << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}