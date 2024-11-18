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

const int MAXN = 1e5+5, MAXK = 2e7+5;
int n,Q;
string s, t[MAXN];
vector<int> v[MAXN];
vector<UM<char,int>> w = {{}};
vector<vector<int>> idx = {{}};
vector<int> num = {0};
int res[MAXN];

void dfs(int cur, int wcur) {
    num[wcur]++;
    FORX(u,v[cur]) {
        if (w[wcur].count(s[u-1])) dfs(u, w[wcur][s[u-1]]);
    }
}

signed main() {
    OPTM;
    cin >> n;
    FOR(i,2,n+1) {
        int tmp; cin >> tmp;
        v[tmp].PB(i);
    }
    v[0].PB(1);
    cin >> s >> Q;
    FOR(i,0,Q) cin >> t[i];
    int sz = 1;
    FOR(i,0,Q) {
        int tn = t[i].size();
        vector<int> curs = {0};
        FOR(j,0,tn) {
            vector<int> tmp;
            int sta = int('a'), en = int('z');
            if (t[i][j] != '*') sta = en = int(t[i][j]);
            FOR(k,sta,en+1) {
                FORX(cur,curs) {
                    char c = char(k);
                    if (!w[cur].count(c)) {
                        w[cur][c] = sz++;
                        w.PB(UM<char,int>());
                        idx.PB(vector<int>());
                        num.PB(0);
                    }
                    tmp.PB(w[cur][c]);
                }
            }
            curs = tmp;
        }
        FORX(cur,curs) idx[cur].PB(i);
    }
    dfs(0, 0);
    FOR(i,0,sz) FORX(u,idx[i]) res[u] += num[i];
    FOR(i,0,Q) cout << res[i] << ln;
}