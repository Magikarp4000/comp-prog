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

const int MAXN = 2e5+1;
int n,q;
int a[MAXN], res[MAXN];
int ft[MAXN*2];
vector<pair<PII,int>> v;
UM<int,int> mp;

bool cmp(pair<PII,int>& x, pair<PII,int>& y) {
    if (x.F.S == y.F.S) return (x.F.F < y.F.F);
    return (x.F.S < y.F.S);
}

void update(int k, int x) {
    k++;
    while (k <= n) {
        ft[k] += x;
        k += k&(-k);
    }
}

int query(int k) {
    k++;
    int cur = 0;
    while (k > 0) {
        cur += ft[k];
        k -= k&(-k);
    }
    return cur;
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,q) {
        int l,r; cin >> l >> r;
        l--; r--;
        v.PB({{l,r},i});
    }
    sort(ALL(v),cmp);
    int idx = 0;
    FOR(i,0,q) {
        int l = v[i].F.F, r = v[i].F.S;
        while (idx <= r) {
            if (mp.count(a[idx])) {
                update(mp[a[idx]],-1);
            }
            mp[a[idx]] = idx;
            update(idx,1);
            idx++;
        }
        int cur = l > 0 ? query(r)-query(l-1) : query(r);
        res[v[i].S] = cur;
    }
    FOR(i,0,q) cout << res[i] << ln;
}