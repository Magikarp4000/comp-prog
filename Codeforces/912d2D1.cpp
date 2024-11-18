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

const int MAXN = 1e5+5, MAXX = 62;
int n,q;
int a[MAXN], b[MAXN];

int solve(int k) {
    FOR(i,0,n) b[i] = a[i];
    int res = 0LL;
    FORR(j,MAXX,-1) {
        int cur = 0LL;
        FOR(i,0,n) {
            int x = b[i]&(1ll<<j) ? 0LL : (1ll<<j)-(b[i]%(1ll<<j));
            if (cur+x > k) {cur = -1; break;}
            cur += x;
        }
        if (cur == -1) continue;
        FOR(i,0,n) {
            if (!(b[i]&(1ll<<j))) b[i] += (1ll<<j)-(b[i]%(1ll<<j));
        }
        res += 1ll<<j;
        k -= cur;
    }
    return res;
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) cin >> a[i];
    FOR(_,0,q) {
        int k; cin >> k;
        cout << solve(k) << ln;
    }
}