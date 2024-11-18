#include "prize.h"
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

const int MAXN = 2e5+5, SQRT = 474;
vector<int> a[MAXN];
int sm = -INF, res = -INF;
bool z[MAXN];

void solve(int l, int r) {
    if (l > r) return;
    int mid = (l+r)/2;
    // cout << "l r: " << l << " " << r << ln;
    vector<int> cur = ask(mid-1);
    if (cur[0]+cur[1] == 0) res = mid;
    else if (cur[0]+cur[1] != sm) {
        int j = mid-1;
        vector<int> cur1 = {-1,-1};
        while (j >= l) {
            cur1 = ask(j-1);
            if (cur1[0]+cur1[1] == 0) {
                res = j;
                return;
            }
            else if (cur1[0]+cur1[1] == sm) break;
            j--;
        }
        // if (j == -1) FOR(k,j+1,mid+1) a[k] = {k+1, sm-k};
        if (j < l) FOR(k,j+1,mid+1) a[k] = {a[j][0]+k-j, a[j][1]-max(0,k-j-1)}, z[k] = 1;
        else FOR(k,j,mid+1) a[k] = {cur1[0]+k-j, cur1[1]-max(0,k-j-1)}, z[k] = 1;
        if (!z[mid+1]) {
            vector<int> cur1 = ask(mid);
            if (cur1[0]+cur1[1] == 0) {
                res = mid+1;
                return;
            }
            else if (cur1[0]+cur1[1] != sm) a[mid+1] = {a[mid][0]+1, a[mid][1]-1};
            else a[mid+1] = cur1;
            z[mid+1] = 1;
        }
        if (j >= l && a[j][0]-a[l-1][0] > 0) solve(l,j-1);
        if (a[mid][1]-a[r+1][1] > 1) solve(mid+1,r);
    }
    else {
        a[mid] = cur;
        z[mid] = 1;
        if (!z[mid+1]) {
            vector<int> cur1 = ask(mid);
            if (cur1[0]+cur1[1] == 0) {
                res = mid+1;
                return;
            }
            else if (cur1[0]+cur1[1] != sm) a[mid+1] = {a[mid][0]+1, a[mid][1]-1};
            else a[mid+1] = cur1;
            z[mid+1] = 1;
        }
        if (a[mid][0]-a[l-1][0] > 0) solve(l,mid);
        if (a[mid][1]-a[r+1][1] > 0) solve(mid+1,r);
    }
}

int find_best(int n) {
	FOR(i,0,min(n,SQRT)) a[i] = ask(i);
    FOR(i,0,min(n,SQRT)) {
        sm = max(sm, a[i][0]+a[i][1]);
    }
    // cout << sm << ln;
    a[0] = {0,sm}, a[n+1] = {sm,0};
    z[0] = z[n+1] = 1;
    solve(1,n);
    return res-1;
}
