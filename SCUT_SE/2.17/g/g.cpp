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
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    DB X, alpha, T, d;
    cin >> n >> X >> alpha >> T >> d;
    alpha = alpha * PI / 180;
    DB light = (X - int(X / T) * T) / T * 2 * PI;
    for (int i = 1; i <= n; i++) {
        DB x, y;
        cin >> x >> y;
        DB theta = atan2(y, x);
        DB ans = 0;
        if (theta >= light - alpha / 2 && theta <= light + alpha / 2) ans = 0;
        else ans = (theta + 2 * PI - (light + alpha / 2)) / (2 * PI) * T;
        cout << ans << endl;
    }
    return 0;
}