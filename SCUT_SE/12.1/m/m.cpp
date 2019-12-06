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
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(8); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        double n, r, l;
        // cin >> n >> r >> l;
        scanf("%lf %lf %lf", &n, &r, &l);
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        double ans = PI * r * r;
        double theta = acos(l / r / 2.0);
        if (2 * r - l > EPS) ans -= 2 * r * r * theta - l * r * sin(theta);
        // cout << ans << endl;
        printf("%.8lf\n", ans * (n - 1) + PI * r * r);
    }    
    return 0;
}