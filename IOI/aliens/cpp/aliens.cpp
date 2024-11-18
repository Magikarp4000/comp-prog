#include "aliens.h"
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

const int MAXN = 5e2+5;
int n;
int dp[MAXN][MAXN];
vector<PII> tmp,v;
deque<PII> dq;

int sq(int x) {return x*x;}

double isct(PII p, PII q) {
    return (double) (q.S-p.S)/(p.F-q.F);
}

int calc(int x, PII p) {
    return p.F*x+p.S;
}

bool cmp(const PII &a, const PII &b) {
    if (a.F == b.F) return a.S > b.S;
    return a.F < b.F;
}

void update(PII p) {
    while (dq.size() >= 2 && isct(p,dq.back()) <= isct(p,dq[dq.size()-2])) dq.pop_back();
    dq.push_back(p);
}

int query(int x) {
    while (dq.size() >= 2 && calc(x,dq[0]) >= calc(x,dq[1])) dq.pop_front();
    return (dq.empty() ? 0LL : calc(x,dq[0]));
}

long long take_photos(int32_t N, int32_t m, int32_t k, vector<int32_t> R, vector<int32_t> C) {
    FOR(i,0,N) tmp.PB({min(R[i],C[i]),max(R[i],C[i])});
    sort(ALL(tmp),cmp);
    int ma = -1LL;
    FOR(i,0,N) if (tmp[i].S > ma) ma = tmp[i].S, v.PB(tmp[i]);
    n = v.size();
    FOR(j,1,k+1) {
        FOR(i,1,n+1) {
            dp[i][j] = sq(v[i-1].S) + query(v[i-1].S);
            int a = -2LL*(v[i-1].F-1LL);
            int d = i > 1 ? sq(max(0LL, v[i-2].S - v[i-1].F + 1LL)) : 0LL; 
            int b = dp[i][j] + sq(v[i-1].F-1LL) - d;
            update({a,b});
        }
    }
    int res = LLINF;
    FOR(j,1,k+1) res = min(res, dp[n][j]);
    return res;
}
