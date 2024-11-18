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
#define PDD pair<double, double>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;
#define int long long

const int MAXN = 1e6+5;
int n;
vector<pair<PII,int>> v;
deque<PII> dq;
int res;

double isct(PII p, PII q) {
    return (double) (q.S-p.S)/(p.F-q.F);
}

int calc(int x, PII p) {
    return p.F*x+p.S;
}

void update(PII p) {
    while (dq.size() >= 2 && isct(p,dq[0]) >= isct(p,dq[1])) dq.pop_front();
    dq.push_front(p);
}

int query(int x) {
    while (dq.size() >= 2 && calc(x,dq.back()) <= calc(x,dq[dq.size()-2])) dq.pop_back();
    return calc(x,dq.back());
}

signed main() {
    OPTM;
    cin >> n;
    FOR(i,0,n) {
        int x,y,a; cin >> x >> y >> a;
        v.PB({{x,y},a});
    }
    sort(ALL(v));
    dq.push_front({0,0});
    FOR(i,0,n) {
        int x = v[i].F.F, y = v[i].F.S, a = v[i].S;
        int cur = x*y-a+query(y);
        res = max(res, cur);
        update({-x,cur});
    }
    cout << res;
}