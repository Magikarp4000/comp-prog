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
const ll LLINF = 2e18+1;

int query(int a, int b) {
    cout << "? " << a+1 << " " << b+1 << endl;
    int x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void answer(int x) {
    cout << "! " << x+1 << endl;
}

void solve() {
    int n; cin >> n;
    int i = 0;
    while (i < n) {
        if (i+1 >= n) {
            answer(i+1);
            return;
        }
        int a = query(i,i+1);
        int b = query(i+1,i);
        if (a != b) {
            int c = i+2 >= n ? query(i,i-1) : query(i,i+2);
            int d = i+2 >= n ? query(i-1,i) : query(i+2,i);
            if (c != d) answer(i);
            else answer(i+1);
            return;
        }
        i += 2;
    }
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) solve();
}