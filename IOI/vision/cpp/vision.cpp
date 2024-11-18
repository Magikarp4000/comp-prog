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

int H,W,K;
int cur,rst,cst,ren,cen,sen;

void init() {
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
}

void rowpre() {
    FOR(i,1,H) {
        FOR(j,0,H-i) {
            vector<int> v = {H*W+j, H*W+j+i};
            add_and(v);
            cur++;
        }
    }
    rst = cur;
}

void rowzero() {
    vector<int> v;
    FOR(i,0,H) v.PB(H*W+i);
    add_xor(v);
    cur++;
}

void rownums() {
    int base = H*W+H+W;
    FOR(i,1,H) {
        vector<int> v;
        FOR(j,0,H-i) v.PB(base+j);
        add_or(v);
        cur++;
        base += H-i;
    }
    ren = cur;
}

void colpre() {
    FOR(i,1,W) {
        FOR(j,0,W-i) {
            vector<int> v = {H*W+H+j, H*W+H+j+i};
            add_and(v);
            cur++;
        }
    }
    cst = cur;
}

void colzero() {
    vector<int> v;
    FOR(i,0,W) v.PB(H*W+H+i);
    add_xor(v);
    cur++;
}

void colnums() {
    int base = ren;
    FOR(i,1,W) {
        vector<int> v;
        FOR(j,0,W-i) v.PB(base+j);
        add_or(v);
        cur++;
        base += W-i;
    }
    cen = cur;
}

void sum() {
    FOR(i,0,K+1) {
        if (i > H-1 || K-i > W-1) continue;
        vector<int> v = {rst+i, cst+K-i};
        add_and(v);
        cur++;
    }
    sen = cur;
}

void finale() {
    vector<int> v;
    FOR(i,cen,sen) v.PB(i);
    add_or(v);
    cur++;
}

void construct_network(int h, int w, int k) {
    H = h, W = w, K = k;
    cur = H*W;
    // init
    init();
    // row
    rowpre();
    rowzero();
    rownums();
    // col
    colpre();
    colzero();
    colnums();
    // final
    sum();
    finale();
}
