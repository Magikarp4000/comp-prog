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
int n,q;
vector<int> v[MAXN];
bool dp[MAXN], dp1[MAXN];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        if (!dp[u]) dp[s] = 1;
    }
    // if (v[s].size() == 1) dp[s] = 1;
}

void reroot(int s, int pa) {
    vector<int> good;
    FORX(u,v[s]) {
        if (!dp[u]) good.PB(u), dp[s] = dp1[s] = 1;
    }
    int orig = dp[s];
    FORX(u,v[s]) {
        if (u == pa) continue;
        if (good.size() == 1 && good[0] == u) dp[s] = 0;
        reroot(u,s);
        dp[s] = orig;
    }
}

signed main() {
    OPTM;
    cin >> n >> q;
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(1,-1);
    reroot(1,-1);
    FOR(_,0,q) {
        int x; cin >> x;
        cout << (dp1[x] ? "Ron" : "Hermione") << ln;
    }
}