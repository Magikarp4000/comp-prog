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
#define in(v,x) (v.find(x) != v.en d())
#define F first
#define S second
#define PII pair<int, int>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

const int MAXN = 251, MAXM = 201, MAXL = 31;
int n,m,l;
set<PII> r[MAXM];
vector<int> v[MAXM];
int d[MAXL][MAXM], a[MAXL];
vector<int> b[MAXN];
bool z[MAXM];

signed main() {
    OPTM;
    cin >> m >> n >> l;
    FOR(i,0,l) cin >> a[i];
    FOR(i,0,m) {
        int k; cin >> k;
        vector<int> tmp;
        FOR(j,0,k) {
            int x; cin >> x;
            tmp.PB(x);
            b[x].PB(i);
        }
        FOR(j,0,k) {
            r[i].insert({min(tmp[j],tmp[(j+1)%k]), max(tmp[j],tmp[(j+1)%k])});
        }
    }
    FOR(i,0,m) {
        FOR(j,i+1,m) {
            FORX(u,r[i]) {
                if (r[j].count(u)) {
                    v[i].PB(j);
                    v[j].PB(i);
                    break;
                }
            }
        }
    }
    FOR(i,0,l) {
        int x = a[i];
        queue<int> q;
        FOR(j,0,m) {
            d[i][j] = INF;
            z[j] = 0;
        }
        FORX(u,b[x]) {
            q.push(u);
            d[i][u] = 0;
        }
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            if (z[s]) continue;
            z[s] = 1;
            FORX(u,v[s]) {
                if (d[i][s]+1 < d[i][u]) {
                    d[i][u] = d[i][s]+1;
                    q.push(u);
                }
            }
        }
    }
    int res = INF, idx = -1;
    FOR(i,0,m) {
        int cur = 0;
        FOR(j,0,l) cur += d[j][i];
        if (cur < res) {
            res = cur;
            idx = i+1;
        }
    }
    cout << res << ln << idx;
}