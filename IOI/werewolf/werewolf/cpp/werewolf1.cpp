#include "werewolf.h"
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

struct Node {
    int mi,ma;
};

const int MAXN = 2e5+5;
vector<int> v[MAXN];
int n,m,Q;
int start;
bool z[MAXN], z1[MAXN];
int pos[MAXN];
Node st[MAXN*4+10];

void dfs(int s, int pa) {
    FORX(u,v[s]) {
        if (u == pa) continue;
        pos[u] = pos[s]+1;
        dfs(u,s);
    }
}

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st[s].mi = st[s].ma = val;
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s].mi = min(st[s*2].mi, st[s*2+1].mi);
        st[s].ma = max(st[s*2].ma, st[s*2+1].ma);
    }
}

int query(int s, int tl, int tr, int l, int r, int tp) {
    if (l <= tl && r >= tr) return tp == 0 ? st[s].mi : st[s].ma;
    else {
        int tm = (tl+tr)/2;
        int cur = tp == 0 ? INF : -INF;
        if (l <= tm) cur = query(s*2,tl,tm,l,r,tp);
        if (r > tm) {
            if (tp == 0) cur = min(cur, query(s*2+1,tm+1,tr,l,r,tp));
            else cur = max(cur, query(s*2+1,tm+1,tr,l,r,tp));
        }
        return cur;
    }
}

bool solve3(int sta, int en, int lt, int rt) {
    if (pos[sta] < pos[en]) {
        int l = pos[sta], r = n-1;
        while (l < r) {
            int mid = (l+r+1)/2;
            int check = query(1,0,n-1,pos[sta],mid,0);
            if (check < lt) r = mid-1;
            else l = mid;
        }
        int sv = l;
        l = 0, r = pos[en];
        while (l < r) {
            int mid = (l+r)/2;
            int check = query(1,0,n-1,mid,pos[en],1);
            if (check > rt) l = mid+1;
            else r = mid;
        }
        int ev = l;
        return sv >= ev;
    }
    else {
        int l = 0, r = pos[sta];
        while (l < r) {
            int mid = (l+r)/2;
            int check = query(1,0,n-1,mid,pos[sta],0);
            if (check < lt) l = mid+1;
            else r = mid;
        }
        int sv = l;
        l = pos[en], r = n-1;
        while (l < r) {
            int mid = (l+r+1)/2;
            int check = query(1,0,n-1,pos[en],mid,1);
            if (check > rt) r = mid-1;
            else l = mid;
        }
        int ev = l;
        return sv <= ev;
    }
}

void reset() {
    FOR(i,0,n) {
        z[i] = z1[i] = 0;
    }
}

bool solve2(int sta, int en, int l, int r) {
    queue<int> q;
    q.push(sta);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        z[s] = 1;
        FORX(u,v[s]) {
            if (z[u] || u < l) continue;
            q.push(u);
        }
    }
    q.push(en);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        z1[s] = 1;
        FORX(u,v[s]) {
            if (z1[u] || u > r) continue;
            q.push(u);
        }
    }
    FOR(i,0,n) if (z[i] && z1[i]) return 1;
    return 0;
}

vector<int> sub2(vector<int> S, vector<int> E, vector<int> L, vector<int> R) {
    vector<int> res;
    FOR(i,0,Q) {
        reset();
        bool ans = solve2(S[i],E[i],L[i],R[i]);
        res.PB(ans);
    }
    return res;
}

vector<int> sub3(vector<int> S, vector<int> E, vector<int> L, vector<int> R) {
    FOR(i,0,n) if (v[i].size() == 1) start = i;
    dfs(start,-1);
    FOR(i,0,n) update(1,0,n-1,pos[i],i);
    vector<int> res;
    FOR(i,0,Q) {
        bool ans = solve3(S[i],E[i],L[i],R[i]);
        res.PB(ans);
    }
    return res;
}

std::vector<int> check_validity(int N, std::vector<int> X, std::vector<int> Y,
                                std::vector<int> S, std::vector<int> E,
                                std::vector<int> L, std::vector<int> R) {
    n = N, m = X.size(), Q = S.size();
    FOR(i,0,m) {
        v[X[i]].PB(Y[i]);
        v[Y[i]].PB(X[i]);
    }
    if (n <= 3000 && m <= 6000 && Q <= 3000) return sub2(S,E,L,R);
    return sub3(S,E,L,R);
}
