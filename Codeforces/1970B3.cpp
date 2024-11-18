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
int a[MAXN], b[MAXN], gf[MAXN];
vector<PII> v;
PII pos[MAXN];

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i], v.PB({a[i],i});
    sort(ALL(v));
    if (n == 2 && v[0].F == 1 && v[1].F == 2) {
        cout << "NO";
        exit(0);
    }
    FOR(i,0,n) b[i] = i;
    bool ok = 0;
    FOR(i,0,n-1) {
        if (v[i].F == 0) {
            swap(b[v[i].S],b[0]);
            gf[v[i].S] = v[i].S;
            ok = 1;
        }
        else if (v[i].F == v[i+1].F) {
            swap(b[v[i+1].S],b[1]);
            swap(b[v[i].S],b[0]);
            gf[v[i].S] = v[i+1].S;
            ok = 1;
        }
        if (ok) break;
    }
    if (!ok) {
        gf[v[n-1].S] = v[n-2].S;
        pos[v[n-2].S] = {n-1, 1}, gf[v[n-2].S] = v[0].S;
        FOR(i,0,n-2) pos[v[i].S] = {i+1, 0}, gf[v[i].S] = v[n-1].S;
    }
    else {
        FOR(i,1,n) {
            int idx = b[i];
            if (a[idx] >= i) pos[idx] = {i, a[idx]-i}, gf[idx] = b[0];
            else pos[idx] = {i, pos[b[i-a[idx]]].S}, gf[idx] = b[i-a[idx]];
        }
    }
    cout << "YES" << ln;
    FOR(i,0,n) cout << pos[i].F+1 << " " << pos[i].S+1 << ln;
    FOR(i,0,n) cout << gf[i]+1 << " ";
}