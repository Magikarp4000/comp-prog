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
#define FORX(u,arr) for (auto u : arr)
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

const string abc[3] = {"O", "XOO", "OOOX"};
UM<int,PII> mp;
int n,q;

int check(string s) {
    US<string> z;
    FOR(i,0,s.size()) {
        FOR(j,i,s.size()) {
            string cur = "";
            FOR(k,i,j+1) cur += s[k];
            z.insert(cur);
        }
    }
    return z.size();
}

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) cout << abc[i] << endl;
    FOR(i,0,3) FOR(j,0,3) mp[check(abc[i]+abc[j])] = {i+1, j+1};
    cin >> q;
    FOR(i,0,q) {
        int x; cin >> x;
        cout << mp[x].F << " " << mp[x].S << endl;
    }
}