#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int(1e9+7)
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,s,n) for (int i = s; i > n; i--)
#define ln '\n'
#define int long long
const long long LLINF = 1e18;

const int MAXN = 5e5+5;
int a[MAXN], p[MAXN], st[MAXN*4+10], st1[MAXN*4+10], dp[MAXN];
unordered_map<int,int> mp;

void update(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st[s] = max(st[s], val);
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update(s*2,tl,tm,idx,val);
        else update(s*2+1,tm+1,tr,idx,val);
        st[s] = max(st[s*2], st[s*2+1]);
    }
}

int query(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    else {
        int tm = (tl+tr)/2;
        int cur = LLINF;
        if (l <= tm) cur = query(s*2,tl,tm,l,r);
        if (r > tm) cur = max(cur, query(s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

void update1(int s, int tl, int tr, int idx, int val) {
    if (tl == tr) st1[s] += max(st1[s], val);
    else {
        int tm = (tl+tr)/2;
        if (idx <= tm) update1(s*2,tl,tm,idx,val);
        else update1(s*2+1,tm+1,tr,idx,val);
        st1[s] = max(st1[s*2], st1[s*2+1]);
    }
}

int query1(int s, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return st[s];
    else {
        int tm = (tl+tr)/2;
        int cur = -LLINF;
        if (l <= tm) cur = query1(s*2,tl,tm,l,r);
        if (r > tm) cur = max(cur, query1(s*2+1,tm+1,tr,l,r));
        return cur;
    }
}

void solve() {
    mp.clear();
    int n; cin >> n;
    FOR(i,0,n*4+10) {
        a[i] = p[i] = dp[i] = st[i] = st1[i] = 0;
    }
    FOR(i,0,n) cin >> a[i];
    FOR(i,1,n+1) p[i] = p[i-1]+a[i-1];
    vector<int> v;
    FOR(i,0,n+1) v.push_back(p[i]);
    sort(v.begin(), v.end());
    FOR(i,0,n) mp[v[i]] = i;
    update(1,0,n,mp[0],-1);
    update(1,0,n,n-mp[0]-1,1);
    FOR(i,0,n) {
        dp[i] = query(1,0,n,0,mp[p[i]])+i;
        dp[i] = max(dp[i], query1(1,0,n,0,n-mp[p[i]]-1))-i;
        update(1,0,n,mp[p[i]],dp[i]-i);
        update1(1,0,n,n-mp[p[i]]-1,dp[i]+i);
    }
    cout << dp[n-1]+1 << ln;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}