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

const int MAXN = 8e2+1;
int n,m,p;
vector<PII> v[MAXN];
int dp[MAXN], dp1[MAXN], w[MAXN];

class Compare {
    public:
        bool operator() (const pair<PII,int>& x, const pair<PII,int>& y) {
            if (x.F.F == y.F.F) return x.F.S > y.F.S;
            return x.F.F < y.F.F;
        }
};

signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> p;
        FOR(i,1,n+1) {
            v[i].clear();
        }
        FOR(i,1,n+1) cin >> w[i];
        FOR(i,0,m) {
            int a,b,s; cin >> a >> b >> s;
            v[a].PB({b,s});
        }
        PQ<pair<PII,int>,vector<pair<PII,int>>,Compare> pq;
        pq.push({{0,p},1});
        while (!pq.empty()) {
            int num = pq.top().F.F, cur = pq.top().F.S, s = pq.top().S;
            pq.pop();
            int best = -INF;
            
            FOR(i,1,n+1) {
                int x = (u.S-cur+1)/w[i];
                int rem = cur+x*w[i]-u.S;
                if (dp[s][+x < dp[u.F]) {
                    dp[u.F] = dp[s]+x;
                    dp1[u.F] = rem;
                }
            }
            FORX(u,v[s]) {
                if (w[u.F] > w[])
            }
        }
    }
}