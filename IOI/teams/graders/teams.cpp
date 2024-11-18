#include "teams.h"
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

const int MAXN = 1e5+5;
int n,m;
vector<PII> v;

bool cmp(const PII &x, const PII &y) {
    if (x.S == y.S) return x.F < y.F;
    return x.S < y.S;
}

void init(int N, int A[], int B[]) {
    n = N;
    FOR(i,0,n) v.PB({A[i],B[i]});
    sort(ALL(v),cmp);
}

int can(int M, int K[]) {
	m = M;
    multiset<PII> s;
    FOR(i,0,m) s.insert({K[i],K[i]});
    FOR(i,0,n) {
        if (s.empty()) return 1;
        auto it = s.lower_bound({v[i].F,0});
        if (it == s.end()) continue;
        PII cur = *it;
        if (cur.F <= v[i].S) {
            s.erase(it);
            if (cur.S-1 > 0) s.insert({cur.F,cur.S-1});
        }
    }
    return s.empty();
}
