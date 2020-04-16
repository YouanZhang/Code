#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <DB, DB> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
P a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(10); cout << fixed;
    int n; double x, y;
    cin >> n >> x >> y;
    double ans = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        DB X, Y, R;
        cin >> X >> Y >> R;
        a[i] = P(sqrt((x - X) * (x - X) + (y - Y) * (y - Y)) - R, R);
    }
    sort(a + 1, a + 1 + n);
    double sumr = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i].first - sumr);
        sumr += a[i].second;
    }
    cout << ans << endl;
    return 0;
}