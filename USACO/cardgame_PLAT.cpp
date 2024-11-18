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
    int x,rb,re;
};

const int MAXN = 1e5+2;
int n;
vector<int> b,e;
bool z[MAXN];
Node st[MAXN*4+10], st1[MAXN*4+10];

void update(Node t[], int s, int tl, int tr, int idx, int tp, int val) {
    if (tl == tr) {
        if (tp == 0) t[s].rb += val;
        else t[s].re += val;
        t[s].x = 0;
    }
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(t,s*2,tl,tm,idx,tp,val);
        else update(t,s*2+1,tm+1,tr,idx,tp,val);
        int c = t == st ? min(t[s*2].re, t[s*2+1].rb) : min(t[s*2].rb, t[s*2+1].re);
        t[s] = {t[s*2].x+t[s*2+1].x+c, t[s*2].rb+t[s*2+1].rb-c, t[s*2].re+t[s*2+1].re-c};
    }
}

Node query(Node t[], int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return t[s];
    else {
        int tm = (tl+tr)/2;
        Node ans = {0,0,0};
        int rem = 0;
        if (t == st) {
            if (l <= tm) {
                ans = query(t,s*2,tl,tm,l,r);
                rem = ans.re;
            }
            else {
                Node cur = query(t,s*2+1,tm+1,tr,l,r);
                int c = min(cur.rb, rem);
                ans = {ans.x+c, ans.rb-c, ans.re-c};
            }
            return ans;
        }
        else {
            if (r > tm) {
                ans = query(t,s*2+1,tm+1,tr,l,r);
                rem = ans.re;
            }
            else {
                Node cur = query(t,s*2,tm,tl,l,r);
                int c = min(cur.rb, rem);
                ans = {ans.x+c, ans.rb-c, ans.re-c};
            }
            return ans;
        }
    }
}

void update_(Node t[], int idx, int tp, int val) {update(t,1,0,MAXN-1,idx,tp,val);}
Node query_(Node t[], int l, int r) {return query(t,1,0,MAXN-1,l,r);}

signed main() {
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) {
        int x; cin >> x;
        e.PB(x);
        z[x] = 1;
    }
    FOR(i,1,2*n+1) if (!z[i]) b.PB(i);
    sort(ALL(b),greater<int>());
    FOR(i,0,n) {
        update_(st1,b[i],0,1);
        update_(st1,e[i],1,1);
    }
    int res = st[1].x+st1[1].x;
    FOR(i,0,n) {
        update_(st,b[i],0,1);
        update_(st,e[i],1,1);
        update_(st1,b[i],0,-1);
        update_(st1,e[i],1,-1);
        res = max(res, st[1].x+st1[1].x);
    }
    cout << res;
}