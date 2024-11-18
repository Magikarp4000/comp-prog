#include "vision.h"
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
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;

void construct_network(int H, int W, int K) {
    int cur = H*W;
    // everything
    FOR(i,0,H) {
        vector<int> v;
        FOR(j,0,W) v.PB(i*W+j);
        add_or(v);
        cur++;
    }
    FOR(j,0,W) {
        vector<int> v;
        FOR(i,0,H) v.PB(i*W+j);
        add_or(v);
        cur++;
    }
    // row
    int base = H*W, rst = cur;
    FOR(i,0,H-1) {
        vector<int> v = {base+i, base+i+1};
        add_and(v);
        cur++;
    }
    int r1 = cur;
    vector<int> v;
    FOR(i,0,H) v.PB(H*W+i);
    add_xor(v);
    cur++;
    if (H > 1) {
        v.clear();
        FOR(i,0,H-1) v.PB(rst+i);
        add_or(v);
        cur++;
    }
    // col
    base = H*W+H;
    int cst = cur;
    FOR(i,0,W-1) {
        vector<int> v = {base+i, base+i+1};
        add_and(v);
        cur++;
    }
    int c1 = cur;
    v.clear();
    FOR(i,0,W) v.PB(H*W+H+i);
    add_xor(v);
    cur++;
    if (W > 1) {
        v.clear();
        FOR(i,0,W-1) v.PB(cst+i);
        add_or(v);
        cur++;
    }
    // final
    if (H == 1) {
        v = {c1+1};
        add_and(v);
        return;
    }
    if (W == 1) {
        v = {r1+1};
        add_and(v);
        return;
    }
    v = {r1,c1+1};
    add_and(v);
    cur++;
    v = {r1+1,c1};
    add_and(v);
    cur++;
    v = {cur-2,cur-1};
    add_or(v);
    cur++;
}
