#include "doll.h"
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

const int MAXN = 6e5+20;
int n,m;
vector<int> a,c,x,y;
bool z[MAXN], t[MAXN];
int cnt,pos;

void solve(int s, int l, int r) {
    if (l == r) {
        if (cnt < n) cnt++, z[s] = 1;
        else z[s] = 0;
        return;
    }
    int mid = (l+r)/2;
    solve(s*2+1,mid+1,r);
    solve(s*2,l,mid);
    z[s] = z[s*2] || z[s*2+1];
}

void solve1(int s, int idx, int l, int r) {
    if (!z[s]) return;
    if (l+1 == r) {
        if (!z[s*2+1]) y[idx] = -1;
        else y[idx] = -INF;
        if (!z[s*2]) x[idx] = -1;
        else x[idx] = -INF;
        return;
    }
    int mid = (l+r)/2;
    if (z[s*2+1]) y[idx] = pos--;
    else y[idx] = -1;
    if (z[s*2]) x[idx] = pos--;
    else x[idx] = -1;
    solve1(s*2+1,-y[idx]-1,mid+1,r);
    solve1(s*2,-x[idx]-1,l,mid);
}

void set_exits() {
    int cur = -1, idx = 1;
    while (idx <= n) {
        int i = -cur-1;
        if (t[i] == 0) {
            if (x[i] == -INF) x[i] = a[idx++], cur = -1;
            else cur = x[i];
        }
        else {
            if (y[i] == -INF) y[i] = a[idx++], cur = -1;
            else cur = y[i];
        }
        t[i] ^= 1;
    }
}

void create_circuit(int M, vector<int> A) {
    n = A.size(), m = M;
    FOR(i,0,n) a.PB(A[i]);
    a.PB(0);
    c.PB(a[0]);
    FOR(i,1,m+1) c.PB(-1);
    int lg = ceil(log2(n)), ub = 1;
    FOR(_,0,max(1,lg)) ub *= 2;
    solve(1,0,ub-1);
    FOR(i,0,ub) x.PB(-1), y.PB(-1);
    pos = -2;
    solve1(1,0,0,ub-1);
    while (!x.empty() && x.back() == -1 && y.back() == -1) x.pop_back(), y.pop_back();
    set_exits();
    answer(c,x,y);
}
