#include "prison.h"
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
 
const int MAXM = 22, MAXN = 5e3+1, LOG = 7;
int a[MAXN][LOG+1];
 
std::vector<std::vector<int>> devise_strategy(int n) {
    // base 3
    FOR(i,1,n+1) {
        int k = i, num = 0;
        while (k) {
            a[i][num] = k%3;
            k /= 3;
            num++;
        }
    }
    vector<vector<int>> v(MAXM+1,vector<int>(n+1,0));
    FOR(j,1,n+1) {
        if (a[j][LOG] == 0) v[0][j] = 3;
        else v[0][j] = a[j][LOG];
    }
    FOR(i,1,MAXM) {
        int idx = (i+2)/3;
        int t = idx%2, pos = LOG-((i-1)/3), prev = i%3;
        v[i][0] = t;
        FOR(j,1,n+1) {
            int cur = a[j][pos];
            if (cur > prev) v[i][j] = t ? -1 : -2;
            else if (cur < prev) v[i][j] = t ? -2 : -1;
            else if (pos-1 == 0) {
                // inspect B
                if (a[j][0] == 0) v[i][j] = -2;
                else if (a[j][0] == 2) v[i][j] = -1;
                else v[i][j] = MAXM;
            }
            else {
                if (a[j][pos-1] == 0) v[i][j] = min(MAXM,idx*3+a[j][pos-1]+3);
                else v[i][j] = min(MAXM,idx*3+a[j][pos-1]);
            }
        }
    }
    // last inspect is A
    FOR(j,1,n+1) v[MAXM][j] = a[j][0] == 0 ? -1 : -2;
    return v;
}