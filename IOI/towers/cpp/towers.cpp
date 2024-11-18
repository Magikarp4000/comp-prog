#include "towers.h"
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

struct Node {
    int ma,mi,pos;
};

const int MAXN = 1e5+5;
int n,l,r,d;
int h[MAXN], le[MAXN], ri[MAXN], p[MAXN];
bool done, z[MAXN];
Node st[MAXN*4+10];
set<int> s;

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        st[s].ma = st[s].mi = val;
        st[s].pos = tl;
    }
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s].ma = max(st[s*2].ma, st[s*2+1].ma);
        st[s].pos = st[s*2].ma > st[s*2+1].ma ? st[s*2].pos : st[s*2+1].pos;
        st[s].mi = min(st[s*2].mi, st[s*2+1].mi);
    }
}

PII query(int s, int tl, int tr, int l, int r, int tp) {
    // tp is type of query
    // 0: range min
    // 1: index of range max
    if (l <= tl && r >= tr) {
        return tp == 1 ? make_pair(st[s].ma, st[s].pos) : make_pair(st[s].mi, -1LL);
    }
    else {
        int tm = (tl+tr)/2;
        PII cur = {LLINF,-1};
        if (tp == 1) cur = {-LLINF,-1};
        if (l <= tm) cur = query(s*2,tl,tm,l,r,tp);
        if (r > tm) {
            PII ncur = query(s*2+1,tm+1,tr,l,r,tp);
            if (tp == 0) {
                if (ncur.F < cur.F) cur = ncur;
            }
            else {
                if (ncur.F > cur.F) cur = ncur;
            }
        }
        return cur;
    }
}

void precalc() {
    FOR(i,0,n) update(1,0,n-1,i,h[i]);
    PQ<PII> pq;
    FOR(i,0,n) {
        while (!pq.empty() && -pq.top().F <= h[i]-d) {
            ri[pq.top().S] = i;
            pq.pop();
        }
        pq.push({-h[i],i});
    }
    while (!pq.empty()) {
        ri[pq.top().S] = n;
        pq.pop();
    }
    FORR(i,n-1,-1) {
        while (!pq.empty() && -pq.top().F <= h[i]-d) {
            le[pq.top().S] = i;
            pq.pop();
        }
        pq.push({-h[i],i});
    }
    while (!pq.empty()) {
        le[pq.top().S] = -1;
        pq.pop();
    }
    vector<PII> v;
    FOR(i,0,n) v.PB({h[i],i});
    int vn = v.size();
    sort(ALL(v));
    s.insert(-LLINF);
    s.insert(LLINF);
    FOR(i,0,vn) {
        int idx = v[i].S;
        auto it = s.lower_bound(idx);
        auto it1 = it;
        it1--;
        if (le[idx] > (*it1) && ri[idx] < (*it)) s.insert(idx);
    }
    FORX(u,s) {
        if (u == LLINF || u == -LLINF) continue;
        p[u+1]++;
        z[u] = 1;
    }
    FOR(i,1,n+1) p[i] += p[i-1];
    // FOR(i,0,n) cout << z[i] << " ";
    // cout << ln;
}

void init(int32_t N, std::vector<int32_t> H) {
    n = N;
    FOR(i,0,n) h[i] = H[i]*1LL;
}

int32_t max_towers(int32_t L, int32_t R, int32_t D) {
    l = L, r = R, d = D;
    if (!done) {
        precalc();
        done = 1;
    }
    if (l == r) return 1;
    int res = p[r+1]-p[l];
    int a = *s.lower_bound(l);
    if (a == LLINF) a = n;
    if (a > l+1) {
        int idx = query(1,0,n-1,l,a-1,1).S;
        if (idx > l) {
            int x = query(1,0,n-1,l,idx-1,0).F;
            if (x <= h[idx]-d) res++;
        }
    }
    auto it = s.upper_bound(r);
    it--;
    int b = *it;
    if (b == -LLINF) b = -1;
    if (b < r-1) {
        int idx = query(1,0,n-1,b+1,r,1).S;
        if (idx < r) {
            int x = query(1,0,n-1,idx+1,r,0).F;
            if (x <= h[idx]-d) res++;
        }
    }
    if (a > r && res == 0) return 1;
    return res;
}
