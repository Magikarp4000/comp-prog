#include "highway.h"
#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+7)
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

struct Edge {
    int x,y,depth;
};

const int MAXN = 1.3e5+5;
int n,m;
vector<PII> v[MAXN], tour;
vector<int32_t> w;
vector<Edge> e;
int dist[2][MAXN], eist[2][MAXN], ans;
bool intree[MAXN];

// void dfs(int s, int pa, vector<PII> vec[]) {
//     FORX(u,vec[s]) {
//         if (u.F == pa) continue;
//         if (e[u.S].y != u.F) swap(e[u.S].x, e[u.S].y);
//         tour.PB(u.S);
//         dfs(u.F,s,vec);
//     }
// }

void pre_bfs(int start, int idx) {
    FOR(i,0,n) dist[idx][i] = INF;
    dist[idx][start] = 0;
    queue<int> q;
    q.push(start);
    vector<bool> z(n,0);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        if (z[s]) continue;
        z[s] = 1;
        FORX(u,v[s]) {
            if (dist[idx][s]+1 < dist[idx][u.F]) {
                dist[idx][u.F] = dist[idx][s]+1;
                // eist[idx][u.S] = dist[idx][u.F];
                q.push(u.F);
            }
        }
    }
}

int find_edge() {
    int l = 0, r = m-1;
    while (l < r) {
        FOR(i,0,m) w[i] = 0;
        int mid = (l+r+1)/2;
        FOR(i,mid,m) w[i] = 1;
        int val = ask(w);
        if (val == ans) r = mid-1;
        else l = mid;
    }
    return l;
}

int find_edge1(int orig) {
    // tour.clear();
    // dfs(s,pa,vec);
    // FORX(u,tour) cout << u.S << " ";
    // cout << ln;
    // FOR(i,0,m) cout << intree[i] << " ";
    // cout << ln;
    // && max(e[tour[i].S].x,e[tour[i].S].y) == 12
    int flowey = tour.size();
    int l = -1, r = flowey-1;
    // FOR(i,0,(tour.size())) {
    //     if (min(e[tour[i].S].x,e[tour[i].S].y) == 10) {
    //         cout << "NYAHAAH " << i << " " << e[tour[i].S].x << " " << e[tour[i].S].y << ln;
    //     }
    // }
    // cout << "intree4 " << intree[1] << ln;
    
    while (l < r) {
        // FOR(i,0,m) w[i] = !intree[i];
        FOR(i,0,m) w[i] = !intree[i];
        int mid = (l+r+1)/2;
        FOR(i,mid,flowey) w[tour[i].S] = 1;
        w[orig] = 0;
        // cout << "l r: " << l << " " << mid << " " << r << ln;
        // cout << "w[1]: " << w[1] << ln;
        int val = ask(w);
        // cout << val;
        if (val == ans) r = mid-1;
        else {
            // if (mid == 13 && r == 13) cout << "NYEHEHEHE " << e[tour[11].S].x << " " << e[tour[11].S].y << ln;
            l = mid;
        }
    }
    // cout << "s l tour[l]: " << s << " " << l << " " << tour[l].S << ln;
    return l == -1 ? -1 : tour[l].S;
}

void bfs(int start, int idx) {
    FOR(i,0,m) intree[i] = 1;
    tour.clear();
    queue<int> q;
    q.push(start);
    vector<int> d(n,INF);
    vector<PII> p(n,{-1,-1});
    vector<bool> z(n,0);
    d[start] = 0LL;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        if (z[s]) continue;
        z[s] = 1;
        // cout << s << " ";
        FORX(u,v[s]) {
            if (dist[idx][u.F] < dist[idx^1][u.F]) {
                if (d[s]+1 < d[u.F]) {
                    d[u.F] = d[s]+1;
                    if (e[u.S].y != u.F) swap(e[u.S].x, e[u.S].y);
                    if (dist[idx][u.F] < dist[idx^1][u.F]) tour.PB({d[u.F],u.S});
                    q.push(u.F);
                }
                else if (d[s]+1 == d[u.F]) intree[u.S] = 0;
            }
            else intree[u.S] = 0;
        }
    }
    sort(ALL(tour));
    // FOR(i,0,n) cout << p[i].F << " ";
    // cout << ln;
    // cout << ln;
    // FOR(i,0,n) {
    //     if (p[i].F != -1) {
    //         vec1[p[i].F].PB({i,p[i].S});
    //         vec1[i].PB(p[i]);
    //         intree[p[i].S] = 1;
    //     }
    // }
}

void find_pair(int32_t N, std::vector<int32_t> U, std::vector<int32_t> V, int32_t A, int32_t B) {
    n = N; m = U.size();
    FOR(i,0,m) {
        v[U[i]].PB({V[i],i});
        v[V[i]].PB({U[i],i});
        e.PB({U[i],V[i],-1LL});
    }
    // bfs(0,-1,v,v1);
    // FOR(i,0,m) cout << intree[i] << " ";
    // cout << ln;
    FOR(i,0,m) w.PB(0);
    ans = ask(w);
    // cout << ans << ln;
    int edge = find_edge();
    // cout << "x y: " << e[edge].x << " " << e[edge].y << ln;
    int xs = e[edge].x, ys = e[edge].y;
    pre_bfs(xs,0);
    pre_bfs(ys,1);
    // cout << "xs ys: " << xs << " " << ys << ln;
    
    // FOR(i,0,n) {
    //     cout << i << ": ";
    //     FORX(u,v2[i]) cout << u.F << " ";
    //     cout << ln;
    // }
    // return;
    bfs(xs,0);
    int edge1 = find_edge1(edge);
    int s = edge1 == -1 ? xs : e[edge1].y;
    // cout << xs << ln;
    // if (s == xs) while (true) int bruh = 0;
    bfs(ys,1);
    int edge2 = find_edge1(edge);
    int t = edge2 == -1 ? ys : e[edge2].y;
    // cout << "S T: " << s << " " << t << ln;
    FOR(i,0,m) w[i] = 0;
    answer(s,t);
}
