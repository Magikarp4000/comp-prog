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

const int MAXN = 1.1e6+5;
int n;
int a[MAXN], l[MAXN];
vector<int> b[MAXN*2];

signed main() {
    freopen("empodia.in","r",stdin);
    freopen("empodia.out","w",stdout);
    OPTM;
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    stack<int> st;
    FORR(i,n-1,-1) {
        while (!st.empty() && a[i] > a[st.top()]) {
            int cur = st.top();
            l[cur] = i+1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        int cur = st.top();
        l[cur] = 0;
        st.pop();
    }
    int res = 0, ma = -1;
    vector<PII> resv;
    FOR(i,0,n) {
        while (!st.empty() && a[st.top()] > a[i]) {
            int cur = st.top();
            st.pop();
            b[a[cur]-cur+MAXN].pop_back();
        }
        if (!b[a[i]-i+MAXN].empty()) {
            int cur = b[a[i]-i+MAXN].back();
            if (cur >= l[i] && cur > ma) {
                resv.PB({cur+1,i+1});
                res++;
                ma = cur;
            }
        }
        st.push(i);
        b[a[i]-i+MAXN].PB(i);
    }
    cout << res << ln;
    FORX(u,resv) cout << u.F << " " << u.S << ln;
}