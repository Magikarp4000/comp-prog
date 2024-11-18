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
int a[MAXN], ft[MAXN];

void update(int k, int x) {
    while (k <= n) {
        ft[k] += x;
        k += k&-k;
    }
}

int query(int r) {
    int sum = 0;
    while (r >= 1) {
        sum += ft[r];
        r -= r&-r;
    }
    return sum;
}

signed main() {
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    int cnt = 1;
    update(a[n-1],1);
    FORR(i,n-2,-1) {
        if (a[i] > a[i+1]) break;
        update(a[i],1);
        cnt++;
    }
    cout << n-cnt << ln;
    FOR(i,0,n-cnt) {
        int k = n-cnt-i+query(a[i]-1)-1;
        update(a[i],1);
        cout << k;
        if (i != n-cnt-1) cout << " ";
    }
}