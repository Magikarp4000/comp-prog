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

const int LOG = 30;

int a,b,c,d;
int s,s1,s2;

signed main() {
    cout << "? " << a << " " << b << endl;
    cin >> s;
    FORR(i,LOG-1,-1) {
        int c = a+(1<<i), d = b+(1<<i);
        cout << "? " << c << " " << b << endl;
        cin >> s1;
        cout << "? " << c << " " << d << endl;
        cin >> s2;
        if (s == 1) {
            if (s1 == 1) {
                if (s2 == 1) {
                    s = 1;
                }
                else {
                    a += 1<<i;
                    s = 1;
                }
            }
            else if (s1 == -1) {
                if (s2 == 1) {
                    a += 1<<i; b += 1<<i;
                    s = 1;
                }
                else {
                    a += 1<<i;
                    s = -1;
                }
            }
            else {
                a += 1<<i;
                s = 0;
            }
        }
        else if (s == -1) {
            if (s1 == 1) {
                if (s2 == 1) {
                    b += 1<<i;
                    s = 1;
                }
                else {
                    s = -1;
                }
            }
            else if (s1 == -1) {
                if (s2 == 1) {
                    b += 1<<i;
                    s = -1;
                }
                else {
                    a += 1<<i; b += 1<<i;
                    s = -1;
                }
            }
            else {
                b += 1<<i;
                s = 0;
            }
        }
        else {
            if (s1 == 1) {
                s = 0;
            }
            else {
                a += 1<<i; b += 1<<i;
                s = 0;
            }
        }
    }
    cout << "! " << a << " " << b << endl;
}