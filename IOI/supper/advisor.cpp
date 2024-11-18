#include "advisor.h"
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

const int MAXN = 1e5+1;
int n,k,m;
int last[MAXN], last1[MAXN], req[MAXN], rem[MAXN], remc[MAXN];
bool z[MAXN];

void ComputeAdvice(int *C, int N, int K, int M) {
    n = N; k = K; m = M;
    FOR(i,0,n) last[i] = INF;
    FORR(i,n-1,-1) {
        req[i] = last[C[i]];
        last[C[i]] = i;
    }
    PQ<PII> pq;
    FOR(i,0,k) {
        z[i] = 1;
        pq.push({last[i],i});
    }
    vector<char> v;
    FOR(i,0,n) {
        if (z[C[i]]) {
            remc[i] = -1;
            pq.push({req[i],C[i]});
        }
        else {
            while (!pq.empty() && !z[pq.top().S]) pq.pop();
            int s = pq.top().S;
            pq.pop();
            remc[i] = s;
            z[s] = 0;
            z[C[i]] = 1;
            pq.push({req[i],C[i]});
        }
    }
    FOR(i,0,n) last1[i] = INF;
    FORR(i,n-1,-1) {
        rem[i] = last1[C[i]];
        if (remc[i] != -1) last1[remc[i]] = i;
    }
    FOR(i,0,k) {
        if (last[i] < last1[remc[i]]) WriteAdvice(1);
        else WriteAdvice(0);
    }
    FOR(i,0,n) {
        if (req[i] < rem[i]) WriteAdvice(1);
        else WriteAdvice(0);
    }
    // FOR(i,0,n) cout << req[i] << ' ';
    // cout << ln;
    // FOR(i,0,n) cout << remc[i] << ' ';
    // cout << ln;
}

// int a[MAXN];

// signed main() {
//     OPTM;
//     cin >> n >> k;
//     FOR(i,0,n) cin >> a[i];
//     ComputeAdvice(a,n,k,1);
// }
