#include "seats.h"
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

const int MAXN = 1e6+5;
PII pos[MAXN];
int tp[MAXN], le[MAXN], bt[MAXN], ri[MAXN];
int n,res;

void give_initial_chart(int H, int W, std::vector<int> R, std::vector<int> C) {
    n = H*W;
    FOR(i,0,n) pos[i] = {C[i],R[i]};
    tp[0] = bt[0] = R[0];
    le[0] = ri[0] = C[0];
    res = 1;
    FOR(i,1,n) {
        tp[i] = min(tp[i-1], R[i]);
        le[i] = min(le[i-1], C[i]);
        bt[i] = max(bt[i-1], R[i]);
        ri[i] = max(ri[i-1], C[i]);
        int area = (bt[i]-tp[i]+1)*(ri[i]-le[i]+1);
        if (area == i+1) res++;
    }
}

int swap_seats(int a, int b) {
    if (a > b) swap(a,b);
    swap(pos[a], pos[b]);
    FOR(i,a,b+1) {
        if (i == 0) {
            tp[i] = bt[i] = pos[i].S;
            le[i] = ri[i] = pos[i].F;
            continue;
        }
        int orig = (bt[i]-tp[i]+1)*(ri[i]-le[i]+1) == i+1;
        tp[i] = min(tp[i-1], pos[i].S);
        le[i] = min(le[i-1], pos[i].F);
        bt[i] = max(bt[i-1], pos[i].S);
        ri[i] = max(ri[i-1], pos[i].F);
        int cur = (bt[i]-tp[i]+1)*(ri[i]-le[i]+1) == i+1;
        res += cur-orig;
    }
    return res;
}
