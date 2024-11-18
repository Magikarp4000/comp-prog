#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int MAXN = 1e5+5;
int n,K;
vector<int> v[MAXN];
int dp[MAXN];
bool ok = 1;

void dfs(int s, int pa) {
    unordered_multiset<int> st;
    FORX(u,v[s]) {
        if (u == pa) continue;
        dfs(u,s);
        if (!ok) return;
        if (dp[u] == K-1) continue;
        if (st.count(K-2-dp[u])) st.erase(st.find(K-2-dp[u]));
        else st.insert(dp[u]);
    }
    if (st.size() > 1) ok = 0;
    else if (st.empty()) dp[s] = 0;
    else dp[s] = (*st.begin())+1;
}

void solve_star(int root) {
    FOR(i,0,n) {
        if ((n-1)%i != 0) {
            cout << 0;
            continue;
        }
    }
}

signed main() {
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n-1) {
        int a,b; cin >> a >> b;
        v[a].PB(b);
        v[b].PB(a);
    }
    int root = -1;
    bool star = 1;
    FOR(i,1,n+1) {
        if (v[i].size() > 2 && root == -1) root = i;
        else if (v[i].size() > 2 && root != -1) star = 0;
    }
    if (star) {
        if (root == -1) root = 1;
    }
    FOR(i,1,n) {
        if ((n-1)%i != 0) {
            cout << 0;
            continue;
        }
        K = i, ok = 1;
        dfs(1,-1);
        cout << (ok && !dp[1]);
    }
}