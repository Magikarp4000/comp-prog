#include "dna.h"
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

const int MAXN = 1e5+1;
int n;
int a[MAXN], b[MAXN];
int p[MAXN][3][3];
int w[3][3];

void init(std::string A, std::string B) {
	n = A.length();
	FOR(i,0,n) {
		if (A[i] == 'A') a[i] = 0;
		else if (A[i] == 'C') a[i] = 1;
		else a[i] = 2;
		if (B[i] == 'A') b[i] = 0;
		else if (B[i] == 'C') b[i] = 1;
		else b[i] = 2;
	}
	FOR(i,1,n+1) {
		FOR(j,0,3) {
			FOR(k,0,3) p[i][j][k] += p[i-1][j][k];
		}
		p[i][a[i-1]][b[i-1]]++;
	}
}

int get_distance(int x, int y) {
	int res = y-x+1;
	FOR(j,0,3) FOR(k,0,3) w[j][k] = p[y+1][j][k]-p[x][j][k];
	vector<int> c(3,0), d(3,0);
	FOR(j,0,3) {
		FOR(k,j,3) {
			if (j == k) res -= w[j][k];
			else {
				res -= min(w[j][k],w[k][j]);
				int diff = abs(w[j][k]-w[k][j]);
				if (w[j][k] > w[k][j]) {
					c[j] += diff;
					d[k] += diff;
				}
				else {
					c[k] += diff;
					d[j] += diff;
				}
			}
		}
	}
	FOR(i,0,3) if (c[i] != d[i]) return -1;
	res -= c[0];
	return res;
}
