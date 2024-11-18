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

const int MAXN = 12, MAXM = 5e5+1, MAXK = 1e2+1;
int n,m,q;
int w[MAXN], wu[1<<MAXN], cnt[1<<MAXN];
int f[1<<MAXN][MAXK];

signed main() {
    OPTM;
    cin >> n >> m >> q;
    int total = 0;
    FOR(i,0,n) {
        cin >> w[i];
        total += w[i];
    }
    FOR(i,0,m) {
        int val = 0, cur = 1;
        string x; cin >> x;
        FOR(j,0,n) {
            if (x[j] == '1') val += cur;
            cur <<= 1;
        }
        cnt[val]++;
    }
    FOR(s,0,1<<n) {
        FOR(j,0,n) {
            if (s&(1<<j)) wu[s] += w[j];
        }
    }
    FOR(t,0,1<<n) {
        FOR(s,0,1<<n) {
            int cur = total-wu[s^t];
            if (cur < MAXK) f[t][cur] += cnt[s];
        }
        FOR(i,1,MAXK) f[t][i] += f[t][i-1];
    }
    FOR(_,0,q) {
        string x; int k;
        cin >> x >> k;
        int t = 0, cur = 1;
        FOR(j,0,n) {
            if (x[j] == '1') t += cur;
            cur <<= 1;
        }
        cout << f[t][k] << ln;
    }
}