#include "messy.h"
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

const int MAXN = 130, LOG = 8;
int n;
int lg[MAXN];
vector<int> a[LOG][MAXN];
string orig = "";

void solve(int l, int r) {
    int len = r-l+1;
    int idx = l/len;
    string s = orig;
    FORR(j,lg[n],-1) {
        int cl = 0, cr = (1<<j)-1;
        FOR(i,0,(1<<(lg[n]-j))) {
            if (cr < l || cl > r) {
                FORX(u,a[j][i]) s[u] = '1';
            }
            cl += (1<<j);
            cr += (1<<j);
        }
    }
    US<int> st;
    FORX(u,a[lg[len]][idx]) st.insert(u);
    FOR(i,0,n) {
        if (s[i] == '1') continue;
        s[i] = '1';
        bool ans = check_element(s);
        s[i] = '0';
        if (ans) {
            a[lg[len]-1][idx*2].PB(i);
            st.erase(i);
        }
    }
    FORX(u,st) a[lg[len]-1][idx*2+1].PB(u);
    if (len == 2) return;
    int mid = (l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
}

std::vector<int> restore_permutation(int N, int w, int r) {
    n = N;
    FOR(i,0,n) orig.PB('0');
    FOR(i,1,LOG) lg[1<<i] = lg[1<<(i-1)]+1;
    FOR(i,0,n) a[lg[n]][0].PB(i);
    FOR(k,1,lg[n]+1) {
        for (int j = 0; j < n; j += (1<<k)) {
            string s = orig;
            FOR(i,0,n) {
                if (i < j || i >= j+(1<<k)) s[i] = '1';
            }
            FOR(i,j,j+(1<<(k-1))) {
                s[i] = '1';
                add_element(s);
                s[i] = '0';
            }
        }
    }
    compile_set();
    solve(0,n-1);
    vector<int> res(n,-1);
    FOR(i,0,n) res[a[0][i][0]] = i;
    return res;
}
