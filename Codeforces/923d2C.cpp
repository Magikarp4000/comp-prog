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

const int MAXN = 2e3+5;
vector<PII> v;

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) {
        int n,l; cin >> n >> l;
        v.clear();
        FOR(i,0,n) {
            int a,b; cin >> a >> b;
            v.PB({b,a});
        }
        sort(ALL(v));
        int res = 0;
        FOR(i,0,n) {
            int sum = 0, cnt = 0;
            PQ<int> pq;
            FOR(j,i,n) {
                int a = v[j].S, b = v[j].F;
                while (!pq.empty() && a < pq.top() && sum+a+b-v[i].F > l) {
                    sum -= pq.top();
                    pq.pop();
                    cnt--;
                }
                if (sum+a+b-v[i].F <= l) {
                    pq.push(a);
                    sum += a;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        cout << res << ln;
    }
}