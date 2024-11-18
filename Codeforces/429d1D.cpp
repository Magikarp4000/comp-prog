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

struct Query {
    int l,r,k,idx;
};

const int MAXN = 3e5+1, BLOCK = 548, MAXS = 1e3+1;
int n,q;
int a[MAXN], cnt[MAXN], res[MAXN];
int low = 0;
Query qu[MAXN];
bool z[MAXN];

bool cmp(const Query& x, const Query& y) {
    if (x.l/BLOCK != y.l/BLOCK) return x.l/BLOCK < y.l/BLOCK;
    return (x.l/BLOCK&1) ? x.r > y.r : x.r < y.r;
}

void add(int pos) {
    cnt[a[pos]]++;
}

void rem(int pos) {
    cnt[a[pos]]--;
}

signed main() {
    OPTM;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> q;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,q) {
        cin >> qu[i].l >> qu[i].r >> qu[i].k;
        qu[i].l--; qu[i].r--;
        qu[i].idx = i;
    }
    sort(qu,qu+q,cmp);
    int cl = 0, cr = -1;
    FOR(i,0,q) {
        low = (qu[i].r-qu[i].l+1)/qu[i].k;
        while (cl < qu[i].l) rem(cl++);
        while (cl > qu[i].l) add(--cl);
        while (cr < qu[i].r) add(++cr);
        while (cr > qu[i].r) rem(cr--);
        int mi = INF;
        FOR(_,0,85) {
            int idx = qu[i].l+rng()%(qu[i].r-qu[i].l+1);
            if (cnt[a[idx]] > low) mi = min(mi,a[idx]);
        }
        if (mi == INF) res[qu[i].idx] = -1;
        else res[qu[i].idx] = mi;
    }
    FOR(i,0,q) cout << res[i] << ln;
}