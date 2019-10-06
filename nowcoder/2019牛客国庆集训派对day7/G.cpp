#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
double a[MAXN], sum[MAXN], delta_2[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(8); cout << fixed;
    for (int n, m; cin >> n >> m;) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
            // if (i - m > 0) {
            //     delta_2[i] = (a[i - m] - a[i]) / n;
            //     delta_2[i] = delta_2[i] * delta_2[i];
            //     delta_2[i] += delta_2[i - 1];
            // }
        }
        double ans = 0;
        for (int i = 1; i <= m; i++)
            ans += pow(a[i] - sum[m] / m, 2);
        cout << sqrt(ans / (m - 1)) << endl;
        for (int i = m + 1; i <= n; i++) {
            // cerr << ans << endl;
            ans -= pow(a[i - m] - (sum[i - 1] - sum[i - m - 1]) / m, 2);
            ans += pow(a[i] - (sum[i - 1] - sum[i - m - 1]) / m, 2);
            // cerr << ans << endl;
            ans += m * pow((a[i - m] - a[i]) / m, 2);
            // cerr << ans << endl;
            ans += 2 * (a[i - m] - a[i]) / m * (a[i] - a[i - m]);
            // cerr << ans << endl;
            cout << sqrt(ans / (m - 1)) << endl;
        }
    }
}