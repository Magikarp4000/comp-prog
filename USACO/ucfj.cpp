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
#define int long long

const int MAXN = 2e5+1;
int n;
int a[MAXN];
set<int> s[MAXN];
int st[MAXN], en[MAXN];
vector<PII> v;
int ft[MAXN];
bool z[MAXN];

void update(int k, int x) {
    k++;
    while (k <= n) {
        ft[k] += x;
        k += k&(-k);
    }
}

int query(int k) {
    k++;
    int sum = 0;
    while (k > 0) {
        sum += ft[k];
        k -= k&(-k);
    }
    return sum;
}

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) s[a[i]].insert(i);
    FOR(i,1,n+1) {
        s[i].insert(-1);
        s[i].insert(n);
    }
    FOR(i,0,n-1) {
        st[i] = *s[a[i]].upper_bound(i)-1;
    }
    FOR(i,1,n) {
        auto it = s[a[i]].lower_bound(i);
        it--;
        en[i] = *it+1;
    }
    FOR(i,0,n) v.PB({en[i],i});
    sort(ALL(v),greater<PII>());
    int res = 0;
    FOR(i,0,n-1) {
        while (!v.empty() && v[v.size()-1].F == i) {
            int idx = v[v.size()-1].S;
            update(idx,1);
            z[idx] = 1;
            v.pop_back();
        }
        if (z[i]) {
            update(i,-1);
            z[i] = 0;
        }
        res += query(st[i]);
    }
    cout << res;
}