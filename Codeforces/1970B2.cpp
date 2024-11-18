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

const int MAXN = 2e5+5;
int n;
int a[MAXN], pos[MAXN], gf[MAXN];

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    FOR(i,1,n) {
        if (a[i] >= i) pos[i] = a[i]-i, gf[i] = 0;
        else pos[i] = pos[i-a[i]], gf[i] = i-a[i];
    } 
    cout << "YES" << ln;
    FOR(i,0,n) cout << i+1 << " " << pos[i]+1 << ln;
    FOR(i,0,n) cout << gf[i]+1 << " ";
}