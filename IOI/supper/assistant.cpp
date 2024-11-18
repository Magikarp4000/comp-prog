#include "assistant.h"
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

void Assist(unsigned char *A, int N, int K, int R) {
    const int MAXN = 1e5+1;
    int n,k,r;
    n = N; k = K; r = R;
    int act[MAXN];
    bool z[MAXN];
    FOR(i,0,MAXN) {
        act[i] = z[i] = 0;
    }
    US<int> pas;
    FOR(i,0,k) {
        act[i] = A[i];
        if (!act[i]) pas.insert(i);
    }
    FOR(i,0,k) z[i] = 1;
    FOR(i,k,r) {
        int cur = GetRequest();
        act[cur] = A[i];
        if (z[cur]) continue;
        int x = *pas.begin();
        PutBack(x);
        pas.erase(x);
        z[x] = 0;
        z[cur] = 1;
        if (!act[cur]) pas.insert(cur);
    }
}
