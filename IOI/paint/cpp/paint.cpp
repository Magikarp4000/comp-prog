#include "paint.h"
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

const int MAXN = 2e5+2, MAXK = 1e2+2;
int dp[MAXK][MAXN], dp1[MAXK][MAXN];
int pb[MAXN], pw[MAXN], diff[MAXN];
bool zb[MAXN], zw[MAXN];

std::string solve_puzzle(std::string s, std::vector<int> c) {
    int n = s.length(), k = c.size();
    FOR(i,1,n+1) {
        pb[i] = pb[i-1];
        pw[i] = pw[i-1];
        if (s[i-1] == 'X') pb[i]++;
        if (s[i-1] == '_') pw[i]++;
    }
    FOR(j,0,n) {
        if (s[j] == 'X') break;
        dp[0][j] = 1;
    }
    FOR(i,1,k+1) {
        FOR(j,0,n) {
            int st = j-c[i-1]+1;
            if (st < 0) continue;
            if (j-1 >= 0 && s[j] != 'X') dp[i][j] = dp[i][j-1];
            if (pw[j+1]-pw[st] == 0) {
                if (st == 0 || s[st-1] != 'X') {
                    if (j == n-1 || s[j+1] != 'X') {
                        if (i == 1) {
                            if (st-1 < 0) dp[i][j] = 1;
                            else dp[i][j] = dp[i][j] || dp[i][j] || dp[i-1][st-1];
                        }
                        else if (st-2 >= 0) dp[i][j] = dp[i][j] || dp[i-1][st-2];
                    }
                }
            }
        }
    }
    dp1[k+1][n] = 1;
    FORR(j,n-1,-1) {
        if (s[j] == 'X') break;
        dp1[k+1][j] = 1;
    }
    FORR(i,k,0) {
        FORR(j,n-1,-1) {
            int en = j+c[i-1]-1;
            if (en >= n) continue;
            //cout << j << " " << en << ln;
            if (j+1 < n && s[j] != 'X') dp1[i][j] = dp1[i][j+1];
            if (pw[en+1]-pw[j] == 0) {
                if (j == 0 || s[j-1] != 'X') {
                    if (en == n-1 || s[en+1] != 'X') {
                        if (i == k) {
                            dp1[i][j] = dp1[i][j] || dp1[i+1][en] || dp1[i+1][en+1];
                        }
                        else if (en+2 < n) dp1[i][j] = dp1[i][j] || dp1[i+1][en+2];
                    }
                }
            }
        }
    }
    FOR(j,0,n) {
        if (s[j] == 'X') zw[j] = 0;
        else if (s[j] == '_') zw[j] = 1;
        else {
            if (j == 0) zw[j] = dp1[1][1];
            else if (j == n-1) zw[j] = dp[k][n-2];
            else {
                FOR(i,0,k+1) {
                    zw[j] = zw[j] || (dp[i][j-1] && dp1[i+1][j+1]);
                }
            }
        }
    }
    FOR(i,1,k+1) {
        FOR(j,0,n-c[i-1]+1) {
            int en = j+c[i-1]-1;
            if (j-1 >= 0 && s[j-1] == 'X') continue;
            if (en+1 < n && s[en+1] == 'X') continue;
            if (pw[en+1]-pw[j] > 0) continue;
            bool xd = i == 1, xd1 = i == k;
            bool vl = j-2 < 0 ? xd : dp[i-1][j-2];
            bool vr = en+2 >= n ? xd1 : dp1[i+1][en+2];
            if (vl && vr) diff[j]++, diff[en+1]--;
        }
    }
    FOR(j,1,n) diff[j] += diff[j-1];
    FOR(j,0,n) zb[j] = diff[j] ? 1 : 0;
    string res = "";
    FOR(i,0,n) {
        if (zb[i] && zw[i]) res.PB('?');
        else if (zb[i]) res.PB('X');
        else if (zw[i]) res.PB('_');
    }
    // FOR(j,0,n) cout << zw[j];
    // cout << ln;
    // FORR(i,k+1,0) {
    //     cout << i << ": ";
    //     FOR(j,0,n) cout << dp1[i][j] << " ";
    //     cout << ln;
    // }
    return res;
}
