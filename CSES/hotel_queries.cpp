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

const int MAXN = 2e5+1;
int n,q;
int a[MAXN], st[MAXN*4+10];

void update(int s, int tl, int tr, int idx, int val, int flag) {
    if (tl == tr) {
        if (flag == 0) st[s] = val;
        else if (flag == 1) st[s] -= val;
    }
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val,flag);
        else update(s*2+1,tm+1,tr,idx,val,flag);
        st[s] = max(st[s*2], st[s*2+1]);
    }
}

int walk(int s, int tl, int tr, int val) {
    if (tl == tr) return tl;
    else {
        int tm = (tl+tr)/2;
        if (st[s*2] >= val) return walk(s*2,tl,tm,val);
        else return walk(s*2+1,tm+1,tr,val);
    }
}

signed main() {
    cin >> n >> q;
    FOR(i,0,n) {
        cin >> a[i];
        update(1,0,n-1,i,a[i],0);
    }
    FOR(_,0,q) {
        int x; cin >> x;
        if (x > st[1]) cout << 0;
        else {
            int idx = walk(1,0,n-1,x);
            cout << idx+1;
            update(1,0,n-1,idx,x,1);
        }
        cout << " ";
    }
}