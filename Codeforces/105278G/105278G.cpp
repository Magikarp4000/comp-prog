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

const int MAXN = 2e5+5;
int n;
double m;
double x[MAXN], y[MAXN];

double f(double x1, double x2, double y1, double y2, double m, double xa) {
    return m * (xa-x1) + y1;
}

double get_area(double px, double py, double x1, double x2, double y1, double y2, double m, double xa) {
    return (xa-px) * (f(x1,x2,y1,y2,m,xa) + py) / (double)2.0;
}

double myround(double a) {
    long long b = round(a * 1000000.0);
    double c = b % 1000000;
    double d = c / 1000000;
    long long e = int64_t(a);
    double f = double(e) + d;
    return f;
}

double myround2(double a) {
    return round(a * 1000000.0) / 1000000.0;
}

double asqrt(double a) {
    double eps = 0.00000001;
    double l = 0.0, r = 1e14;
    while (r-l > eps) {
        double mid = (l+r)/2.0;
        if (mid*mid < a) l = mid;
        else r = mid;
    }
    return l;
}

double e[MAXN];

signed main() {
    OPTM;
    // cout << myround(10000.9999900100) << ln;
    // exit(0);
    // cout << asqrt(16.0) << ln;
    // exit(0);
    cin >> n >> m;
    FOR(i,0,n) cin >> x[i];
    FOR(i,0,n) cin >> y[i];
    double total = 0.0;
    FOR(i,1,n) {
        e[i] = (x[i]-x[i-1]) * (y[i]+y[i-1]) / (double)2.0;
        total += e[i];
    }
    double area = total / m;
    double cur = 0.0;
    int i = 1;
    double eps = 0.0000001;
    double px = x[0], py = y[0];
    // m = 200000;
    // cout << sqrt(2938298489.23828829832989238) << ln;
    // cout << 54206.1 * 54206.1 << ln;
    FOR(j,0,m-1) {
        cur = 0.0;
        while (i < n && cur < area) {
            double extra = px == x[i-1] ? e[i] : (x[i]-px) * (y[i]+py) / (double)2.0;
            // double extra = (x[i]-px) * (y[i]+py) / (double)2.0;
            if (cur + extra > area) break;
            cur += extra;
            px = x[i], py = y[i];
            i++;
        }
        double rem = area - cur;
        
        double slop = (y[i]-y[i-1]) / (x[i]-x[i-1]);
        // cout << sqrt(4.0*py*py+8.0*slop*rem)/2.0*slop + px << ln;
        double mid = 0.0;
        if (slop != 0) {
            // cout << slop << " " << rem << " " << py << ln;
            // cout << "bruh thing: " << sqrt(4.0*py*py+8.0*slop*rem) << ln;
            // cout << "bruh thing / 2*slop: " << sqrt(4.0*py*py+8.0*slop*rem)/(2.0*slop) << ln;
            // cout << "-py/slop: " << -py/slop << ln;
            mid = (-py + sqrt(py*py + 2.0*slop*rem)) / slop + px;
        }
        else {
            mid = rem / y[i-1] + px;
        }
        // double mid = 0;
        // double l = x[i-1], r = x[i];
        // double prevl = -1, prevr = -1;
        // while (r-l > eps) {
        //     if (prevl == l && prevr == r) break;
        //     prevl = l;
        //     prevr = r;
        //     mid = (l+r)/(double)2.0;
        //     // cout << l << " " << r << " " << mid <<" " << r-l << ln;
        //     if (get_area(px, py, x[i-1], x[i], y[i-1], y[i], m, mid) < rem - 0.00000001) l = mid;
        //     else r = mid;
        //     // cout << mid-l << " ";
        // }
        cout << fixed << setprecision(7) << mid << ln;
        // mid = myround2(mid);
        px = mid;
        py = slop * (mid - x[i-1]) + y[i-1];
        // py = f(x[i-1], x[i], y[i-1], y[i], slop, mid);
    }
}