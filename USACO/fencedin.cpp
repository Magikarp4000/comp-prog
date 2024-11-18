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

const int MAXN = 5e4+10;
int C,R,n,m;
vector<int> row,col;
bool zr[MAXN], zc[MAXN];

signed main() {
    freopen("fencedin.in","r",stdin);
    freopen("fencedin.out","w",stdout);
    OPTM;
    cin >> C >> R >> n >> m;
    col.PB(0), row.PB(0), col.PB(C), row.PB(R);
    FOR(i,0,n) {
        int a; cin >> a;
        col.PB(a);
    }
    FOR(i,0,m) {
        int b; cin >> b;
        row.PB(b);
    }
    sort(ALL(col)); sort(ALL(row));
    int cn = col.size(), rn = row.size();
    vector<PII> v;
    FOR(i,0,cn-1) v.PB({col[i+1]-col[i],0});
    FOR(i,0,rn-1) v.PB({row[i+1]-row[i],1});
    sort(ALL(v));
    int cnum = 0, rnum = 0, res = 0LL;
    FORX(u,v) {
        int w = u.F, t = u.S;
        if (t == 0) {
            int x = cnum == 0 ? m : min(m, m-rnum+1LL);
            res += x*w;
            cnum++;
        }
        else {
            int x = rnum == 0 ? n : min(n, n-cnum+1LL);
            res += x*w;
            rnum++;
        }
    }
    cout << res;
}