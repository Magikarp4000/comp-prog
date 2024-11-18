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

const int MAXN = 4e5+5;
int n,m;
vector<int> c,x,y,nxt[MAXN];
bool z[MAXN], t[MAXN];

void create_circuit(int M, vector<int> a) {
    n = a.size(), m = M;
    FOR(_,0,m+1) c.PB(0);
    c[0] = a[0];
    a.PB(0);
    FOR(i,0,n) {
        nxt[a[i]].PB(a[i+1]);
    }
    int cur = -1;
    FOR(i,0,n) {
        if (z[a[i]]) continue;
        z[a[i]] = 1;
        int cnt = nxt[a[i]].size(), start = cur;
        if (cnt == 1) {
            c[a[i]] = nxt[a[i]][0];
            continue;
        }
        c[a[i]] = cur;
        cur--;
        int tgt = x.size()+cnt-1;
        int num = 2;
        int lg = ceil(log2(cnt));
        int cnt1 = 1<<lg;
        int thrsh = 2*cnt-cnt1;
        while (num < cnt1) {
            x.PB(cur--);
            num++;
            y.PB(cur--);
            num++;
        }
        int xsz = x.size(), ysz = y.size();
        FOR(_,0,thrsh/2) {
            x.PB(-INF);
            y.PB(-INF);
        }
        FOR(_,0,cnt-thrsh) {
            x.PB(start);
            y.PB(-INF);
        }
        int ball = start, idx = 0;
        while (idx < cnt) {
            int real = -ball-1;
            ball = t[real] ? y[real] : x[real];
            if (ball == -INF) {
                if (t[real] == 0) x[real] = nxt[a[i]][idx];
                else y[real] = nxt[a[i]][idx];
                idx++;
                ball = start;
            }
            t[real] ^= 1;
        }
    }
    // FORX(u,c) cout << u << " ";
    // cout << ln;
    // FORX(u,x) cout << u << " ";
    // cout << ln;
    // FORX(u,y) cout << u << " ";
    // cout << ln;
    answer(c,x,y);
}
