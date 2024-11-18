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

const int MAXN = 1e5+1;
int n;
ll a[MAXN], b[MAXN];
ll ft[MAXN+1];

void update(int k, ll x) {
    while (k <= n+1) {
        ft[k] += x;
        k += k&(-k);
    }
}

ll query(int r) {
    ll sum = 0;
    while (r >= 1) {
        sum += ft[r];
        r -= r&(-r);
    }
    return sum;
}

signed main() {
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) {
        update(a[i]+1,1);
        b[a[i]] += query(n+1)-query(a[i]+1);
    }
    ll cur = 0;
    FOR(i,-1,n-1) {
        if (i >= 0) cur += b[i];
        cout << cur << ln;
    }
}