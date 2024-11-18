#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+7)
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
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 5e3+1;
int n,m,k;
vector<PII> v;
vector<int> s[MAXN];
UM<char,ll> mp;
ll dp[MAXN], p[MAXN];
set<int> sus;
UM<int,int> mp1;

ll bexp(ll x, ll y) {
    x %= INF;
    ll cur = 1;
    while (y > 0) {
        if (y%2 == 1) cur = (cur*x)%INF;
        x = (x*x)%INF;
        y /= 2;
    }
    return cur;
}

signed main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    OPTM;
    cin >> n >> m >> k;
    FOR(i,0,n) {
        int x,t; cin >> x >> t;
        v.PB({x,t});
        sus.insert(t);
    }
    FOR(i,0,m) {
        char c; cin >> c;
        mp[c]++;
    }
    int cnt = 0;
    FORX(u,sus) {
        mp1[u] = cnt;
        cnt++;
    }
    FOR(i,0,n) s[mp1[v[i].S]].PB(v[i].F);
    dp[0] = 1;
    FOR(i,1,k+1) {
        FOR(j,0,n) {
            if (i-v[j].F >= 0) dp[i] = (dp[i]+dp[i-v[j].F])%INF;
        }
    }
    int tn = cnt;
    FOR(i,0,tn) {
        FORX(u,s[i]) p[i] = (p[i]+dp[k-u])%INF;
    }
    ll res = 1;
    FORX(u,mp) {
        ll cur = 0;
        FOR(i,0,tn) {
            ll cur1 = p[i];
            cur = (cur+bexp(cur1,u.S))%INF;
        }
        res = (res*cur)%INF;
    }
    cout << res << ln;
}