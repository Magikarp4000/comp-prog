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
    int x,a,b,c;
};

const int MAXN = 2e5+1;
int n,q;
string s;
int v[MAXN];
Node st[MAXN*4+10];

Node merge(Node le, Node ri) {
    return {
        max(le.b+ri.x, le.x+ri.a),
        max(le.a+ri.a, le.c+ri.x),
        max(le.b+ri.b, le.x+ri.c),
        max(le.a+ri.c, le.c+ri.b)
    };
}

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        st[s] = {val,0LL,0LL,0LL};
    }
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = merge(st[s*2], st[s*2+1]);
    }
}

signed main() {
    freopen("optmilk.in","r",stdin);
    freopen("optmilk.out","w",stdout);
    OPTM;
    cin >> n >> q;
    FOR(i,0,n) {
        int x; cin >> x;
        update(1,0,n-1,i,x);
    }
    int res = 0LL;
    FOR(_,0,q) {
        int k,x; cin >> k >> x;
        k--;
        update(1,0,n-1,k,x);
        res += st[1].x;
    }
    cout << res;
}