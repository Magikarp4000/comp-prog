#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int64_t(1e9+7)
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
const ll LLINF = 5e18+1;
#define int long long

const int MAXN = 1e2+5;
int n,m,t;
set<PII> rg, bg;
UM<string,PII> mp;
UM<string,int> scores;
vector<pair<int,pair<char,string>>> v;
string qp = "";

signed main() {
    OPTM;
    cin >> n >> m;
    FOR(i,0,n) {
        FOR(j,0,m) {
            string x; cin >> x;
            if (x == "..") continue;
            else if (x == "RG") rg.insert({j,i});
            else if (x == "BG") bg.insert({j,i});
            else mp[x] = {j,i};
        }
    }
    cin >> t;
    FOR(i,0,t) {
        string p,act,ball;
        cin >> p >> act;
        int dx = 0, dy = 0;
        if (act == "C") {
            cin >> ball;
            if (ball == ".Q") qp = p;
            else {
                if (p[0] == 'R') v.PB({i, {'s', "RED"}});
                else v.PB({i, {'s', "BLUE"}});
            }
        }
        else if (act == "U") dy = -1;
        else if (act == "D") dy = 1;
        else if (act == "L") dx = -1;
        else if (act == "R") dx = 1;
        mp[p] = {mp[p].F+dx, mp[p].S+dy};
        if (act == "T") mp[".Q"] = mp[qp], qp = "";
        vector<string> toerase;
        FORX(u,mp) {
            if (u.F[0] == '.') continue;
            if (mp.count(".B") && u.S == mp[".B"]) v.PB({i, {'e', u.F}}), toerase.PB(u.F);
        }
        FORX(u,toerase) mp.erase(u);
        if (qp == "" && rg.count(mp[".Q"])) v.PB({i,{'g',"BLUE"}}), qp = "", mp[".Q"] = {(m-1)/2, (n-1)/2};
        if (qp == "" && bg.count(mp[".Q"])) v.PB({i,{'g',"RED"}}), qp = "", mp[".Q"] = {(m-1)/2, (n-1)/2};
    }
    sort(ALL(v));
    FORX(u,v) {
        if (u.S.F == 'g') {
            scores[u.S.S]++;
            cout << u.F << " " << u.S.S << " GOAL" << ln;
        }
        else if (u.S.F == 'e') cout << u.F << " " << u.S.S << " ELIMINATED" << ln;
        else {
            scores[u.S.S] += 10;
            cout << u.F << " " << u.S.S << " CATCH GOLDEN SNITCH" << ln;
        }
    }
    cout << "FINAL SCORE: " << scores["RED"] << " " << scores["BLUE"];
}