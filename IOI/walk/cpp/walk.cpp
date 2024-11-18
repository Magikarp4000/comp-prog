#include "walk.h"
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

const int MAXN = 1e5+5, MAXX = 5e6+10;
int n,m;
vector<pair<int,ll>> v[MAXX];
UM<int,UM<int,int>> mp;
vector<int> row[MAXN], col[MAXN];
vector<PII> in[MAXN], out[MAXN];

long long min_distance(vector<int> x, vector<int> h, vector<int> l, vector<int> r, vector<int> y, int s, int g) {
	n = x.size(), m = l.size();
    int cur = 0;
    set<PII> sw;
    FOR(i,0,m) in[l[i]].PB({y[i],i}), out[r[i]+1].PB({y[i],i});
    FOR(i,0,n) {
        FORX(u,out[i]) sw.erase(u);
        FORX(u,in[i]) sw.insert(u);
        for (auto it = sw.begin(); it != sw.end() && (it->F) <= h[i]; it++) {
            int e = it->F, idx = it->S;
            if (!mp[e].count(i)) mp[e][i] = cur++;
            row[idx].PB(i);
            col[i].PB(e);
        }
    }
    FOR(i,0,n) {
        int cn = col[i].size();
        FOR(j,0,cn-1) {
            int a = mp[col[i][j]][i], b = mp[col[i][j+1]][i];
            v[a].PB({b,col[i][j+1]-col[i][j]});
            v[b].PB({a,col[i][j+1]-col[i][j]});
        }
    }
    FOR(i,0,m) {
        int rn = row[i].size();
        FOR(j,0,rn-1) {
            int a = mp[y[i]][row[i][j]], b = mp[y[i]][row[i][j+1]];
            v[a].PB({b,x[row[i][j+1]]-x[row[i][j]]});
            v[b].PB({a,x[row[i][j+1]]-x[row[i][j]]});
        }
    }
    // FOR(i,0,m) {
    //     int prev = y[i] > h[l[i]] ? -1 : l[i];
    //     FOR(j,l[i],r[i]) {
    //         pos[j].PB(y[i]);
    //         if (y[i] > h[j+1]) continue;
            
    //         if (prev != -1) {
    //             if (!mp[y[i]].count(x[j])) mp[y[i]][x[j]] = cur++;
    //             if (!mp[y[i]].count(x[j+1])) mp[y[i]][x[j+1]] = cur++;
    //             int a = mp[y[i]][x[j]], b = mp[y[i]][x[j+1]];
    //             // cout << "y x mp: " << y[i] << " " << x[j] << " " << mp[y[i]][x[j]] << ln;
    //             v[a].PB({b,1LL*(x[j+1]-x[j])});
    //             v[b].PB({a,1LL*(x[j+1]-x[j])});
    //         }
            
    //         prev = j+1;
    //     }
    //     // cout << "y x mp: " << y[i] << " " << x[r[i]] << " " << mp[y[i]][x[r[i]]] << ln;
    //     pos[r[i]].PB(y[i]);
    // }
    // FOR(i,0,n) sort(ALL(pos[i]));
    // FOR(i,0,n) {
    //     int pn = pos[i].size();
    //     FOR(j,0,pn-1) {
    //         if (pos[i][j] == pos[i][j+1]) continue;
    //         if (pos[i][j+1] > h[i]) continue;
    //         int a = mp[pos[i][j]][x[i]], b = mp[pos[i][j+1]][x[i]];
    //         v[a].PB({b,pos[i][j+1]-pos[i][j]});
    //         v[b].PB({a,pos[i][j+1]-pos[i][j]});
    //     }
    // }
    int st = -1, en = -1;
    if (!col[s].empty()) {
        st = cur;
        int a = mp[col[s][0]][s], b = cur++;
        v[a].PB({b,col[s][0]});
        v[b].PB({a,col[s][0]});
    }
    if (!col[g].empty()) {
        en = cur;
        int a = mp[col[g][0]][g], b = cur++;
        v[a].PB({b,col[g][0]});
        v[b].PB({a,col[g][0]});
    }
    // cout << "st en: " << st << " " << en << ln;
    if (st == -1 || en == -1) return -1;
    // FOR(i,0,cur+1) {
    //     cout << i << ": ";
    //     FORX(u,v[i]) cout << u.F << " ";
    //     cout << ln;
    // }
    PQ<pair<ll,int>> pq;
    vector<ll> d(cur+1,LLINF);
    pq.push({0LL,st});
    d[st] = 0LL;
    while (!pq.empty()) {
        int t = pq.top().S;
        pq.pop();
        FORX(u,v[t]) {
            if (d[t]+u.S < d[u.F]) {
                d[u.F] = d[t]+u.S;
                pq.push({-d[u.F],u.F});
            }
        }
    }
    return (d[en] == LLINF ? -1LL : d[en]);
}
