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

const int MAXN = 2e5+5;
int n;
int a[MAXN];

bool solve() {
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    vector<int> b(n,0);
    int prev = -1, sta = -1;
    FOR(i,0,n) {
        if (a[i] != -1) {
            prev = sta = i;
            break;
        }
    }
    if (sta == -1) {
        FOR(i,0,n) cout << (i%2 ? 2 : 1) << " ";
        cout << ln;
        return 1;
    }
    FOR(i,0,n) if (a[i] != -1) b[i] = a[i];
    bool mult = 1;
    FORR(i,sta-1,-1) {
        if (mult) b[i] = b[i+1]*2;
        else b[i] = b[i+1]/2;
        mult ^= 1;
    }
    FOR(i,sta+1,n) {
        if (a[i] != -1) {
            US<int> s;
            vector<int> vd;
            int c = a[prev], d = a[i];
            while (c) s.insert(c), c >>= 1;
            while (d && !s.count(d)) vd.PB(d), d >>= 1;
            int anc = log2(d), bruh1 = log2(a[prev]), bruh2 = log2(a[i]);
            int dist = bruh1+bruh2-2*anc;
            if (dist > i-prev || dist%2 != (i-prev)%2) return 0;
            int j = prev+1, cur = a[prev];
            while (cur != d) {
                cur >>= 1;
                b[j++] = cur;
            }
            reverse(ALL(vd));
            FORX(u,vd) b[j++] = u;
            bool mult = 1;
            FOR(k,j,i) {
                if (mult) b[k] = b[k-1]*2;
                else b[k] = b[k-1]/2;
                mult ^= 1;
            }
            prev = i;
        }
    }
    mult = 1;
    FOR(i,prev+1,n) {
        if (mult) b[i] = b[i-1]*2;
        else b[i] = b[i-1]/2;
        mult ^= 1;
    }
    FOR(i,0,n) cout << b[i] << " ";
    cout << ln;
    return 1;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        if (!solve()) cout << -1 << ln;
    }
}