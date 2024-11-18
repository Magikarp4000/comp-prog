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

const int MAXN = 1e5+1;
int n;
int s[MAXN];
const string abc = "MBF";
UM<char,int> mp;
int dp[2][4][4][4][4];

int calc(int a, int b, int c) {
    US<int> tmp;
    if (a) tmp.insert(a);
    if (b) tmp.insert(b);
    if (c) tmp.insert(c);
    return tmp.size();
}

signed main() {
    OPTM;
    FOR(i,0,3) mp[abc[i]] = i+1;
    cin >> n;
    FOR(i,0,n) {
        char c; cin >> c;
        s[i] = mp[c];
    }
    FOR(a,0,4) {
        FOR(b,0,4) {
            FOR(c,0,4) {
                FOR(d,0,4) {
                    dp[0][a][b][c][d] = dp[1][a][b][c][d] = -LLINF;
                }
            }
        }
    }
    // string abc = "weioro33er";
    // abc += "wqejsd";
    dp[0][0][0][0][0] = 0;
    FOR(i,0,n) {
        int x = s[i];
        FOR(a,0,4) {
            FOR(b,0,4) {
                FOR(c,0,4) {
                    FOR(d,0,4) {
                        if (dp[0][a][b][c][d] == -LLINF) continue;
                        dp[1][b][x][c][d] = max(dp[1][b][x][c][d], dp[0][a][b][c][d]+calc(a,b,x));
                        dp[1][a][b][d][x] = max(dp[1][a][b][d][x], dp[0][a][b][c][d]+calc(c,d,x));
                    }
                }
            }
        }
        FOR(a,0,4) {
            FOR(b,0,4) {
                FOR(c,0,4) {
                    FOR(d,0,4) {
                        dp[0][a][b][c][d] = dp[1][a][b][c][d];
                        dp[1][a][b][c][d] = -LLINF;
                    }
                }
            }
        }
    }
    int res = 0;
    FOR(a,0,4) {
        FOR(b,0,4) {
            FOR(c,0,4) {
                FOR(d,0,4) {
                    res = max(res, dp[0][a][b][c][d]);
                }
            }
        }
    }
    cout << res;
}