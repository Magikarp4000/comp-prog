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

const int MAXN = 1e5+1, MAXM = 21, MAXX = 27;

int n;
string s;
int cnt[MAXX][MAXX], dp[1<<MAXM];
bool z[MAXX];
vector<int> v;

signed main() {
    cin >> s;
    n = s.length();
    FOR(i,0,n) {
        if (!z[s[i]-'a']) {
            z[s[i]-'a'] = 1;
            v.PB(s[i]-'a');
        }
    }
    int vn = v.size();
    FOR(i,0,n-1) cnt[s[i]-'a'][s[i+1]-'a']++;
    FOR(s,0,1<<vn) dp[s] = INF;
    dp[0] = 1;
    FOR(s,0,1<<vn) {
        FOR(j,0,vn) {
            if (s&(1<<j)) {
                int cur = 0;
                FOR(k,0,vn) {
                    if (s&(1<<k)) cur += cnt[v[j]][v[k]];
                }
                dp[s] = min(dp[s], dp[s^(1<<j)]+cur);
            }
        }
    }
    cout << dp[(1<<vn)-1];
}