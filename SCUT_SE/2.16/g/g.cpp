#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const DB g = 10;
int n;
DB v, L, R;
DB x1, x2;
DB f(DB theta) {
    return v * cos(theta) * 2 * v * sin(theta) / g;
}
DB findang(DB l, DB r, DB x) {
    while (abs(r - l) > EPS) {
        DB mid = (l + r) / 2;
        DB s = f(mid);
        if (s - x > EPS) r = mid;
        else l = mid;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(4); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        cin >> n >> v >> L >> R;
        R = R * PI / 180; L = L * PI / 180;
        // cerr << L << ' ' << R << endl;
        DB xlim = f(PI / 4);
        // cerr << xlim << endl;
        for (; n; n--) {
            cin >> x1 >> x2;
            if (x1 > xlim) {
                DB ans = 0;
                cout << ans << endl;
                continue;
            }
            if (x2 > xlim) x2 = xlim;
            if (R - L < EPS) {
                DB ans = 0;
                if (x1 - f(L) <= EPS && f(L) - x2 <= EPS) {
                    ans = 1;
                }
                else ans = 0;
                cout << ans << endl;
                continue; 
            }
            if (abs(x1 - x2) < EPS) {
                DB ans = 0;
                cout << ans << endl;
                continue;
            }
            DB ansang = 0;
            DB ang1 = findang(0, PI / 4, x1);
            // DB ang1 = asin(g * x1 / v / v) / 2;
            // cerr << "ang1 = " << ang1 << endl;
            DB ang2 = findang(0, PI / 4, x2);
            // DB ang2 = asin(g * x2 / v / v) / 2;
            // cerr << "ang2 = " << ang2 << endl;
            if (ang1 >= R) ansang += 0;
            else if (ang2 <= L) ansang += 0;
            else ansang += min(R, ang2) - max(L, ang1);
            // cerr << ansang << endl;
            ang1 = findang(PI / 2, PI / 4, x2);
            // ang1 = PI / 2 - ang1;
            // cerr << "ang1 = " << ang1 << endl;
            ang2 = findang(PI / 2, PI / 4, x1);
            // ang2 = PI / 2 - ang2;
            // cerr << "ang2 = " << ang2 << endl;
            if (ang1 >= R) ansang += 0;
            else if (ang2 <= L) ansang += 0;
            else ansang += min(R, ang2) - max(L, ang1);
            cout << ansang / (R - L) << endl;
            // cerr << asin(g * x1 / v / v) / 2 << ' ' << PI / 2 - asin(g * x1 / v / v) / 2 << endl;
            // cerr << asin(g * x2 / v / v) / 2 << ' ' << PI / 2 - asin(g * x2 / v / v) / 2 << endl;
        }
    }
    return 0;
}