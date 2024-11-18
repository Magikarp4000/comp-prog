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

const int MAXN = 2e6+5;
int n,m,k;
vector<PII> v;
UM<int,int> mp;

void solve() {
    cin >> n >> m >> k;
    FOR(i,0,n) {
        int d,a; cin >> d >> a;
        v.PB({d,a});
        mp[d] = a;
    }
    set<int> s;
    int sum = 0;
    FOR(i,0,n) {
        int d = v[i].F, a = v[i].S;
        s.insert(d);
        sum += a;
    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << solve() << ln;
}