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

int n;
string s;
vector<pair<PII,char>> v;

signed main() {
    OPTM;
    cin >> s;
    n = s.size();
    int cur = 0;
    v.PB({{0,0},s[0]});
    FOR(i,1,n) {
        cur += s[i-1] == '(' ? 1 : -1;
        v.PB({{cur,-i},s[i]});
    }
    sort(ALL(v));
    FOR(i,0,n) cout << v[i].S;
}