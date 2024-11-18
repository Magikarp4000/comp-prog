#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int(1e9+7)
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define ln '\n'

bool solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> a(n+1,0), b(n+1,0);
    FOR(i,0,n) {
        a[i+1] = a[i];
        b[i+1] = b[i];
        if (s[i] == 'A') a[i+1]++;
            // if (i > 1 && s[i-1] == 'B') a[i+1] = 1;
            // else a[i+1] = a[i]+1;
            // b[i+1] = b[i];
        // }
        else b[i+1]++;
        //     if (i > 1 && s[i-1] == 'A') b[i+1] = 1;
        //     else b[i+1] = b[i]+1;
        //     a[i+1] = a[i];
        // }
    }
    FOR(i,0,n) {
        if (b[i+1] > a[i+1]) return 0;
    }
    if (s[n-1] != 'B') return 0;
    return 1;
}

signed main() {
    OPTM;
    int T; cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << ln;
}