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

std::vector<int> restore_permutation(int n, int w, int r) {
    string s = "";
    FOR(i,0,n) s.PB('0');
    FOR(i,0,n) {
        s[i] = '1';
        add_element(s);
    }
    compile_set();
    string t = "";
    FOR(i,0,n) t.PB('0');
    vector<int> p(n,-1);
    FOR(i,0,n) {
        FOR(j,0,n) {    
            if (t[j] == '1') continue;
            t[j] = '1';
            if (check_element(t)) {
                p[j] = i;
                break;
            }
            else t[j] = '0';
        }
    }
    return p;
}
