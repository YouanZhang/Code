#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 7;
double E[MAXN];
double ss[MAXN], sum[MAXN], s[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(10); cout << fixed;
    double p, q;
    int n;
    while (cin >> n >> p >> q) {
        s[0] = q; ss[0] = q; sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] * (1 - q);
            ss[i] = ss[i - 1] + s[i];
            sum[i] = sum[i - 1] + s[i] * 2 * i;
        }
        double ans = 0;
        for (int i = 0; i < n; i++) {
            // // E[i] = (1 - p) + (p * (sum[n - i - 1] + (1 - ss[n - i - 1]) * 2 * (n - i)));
            // cerr << s[n - i] / q << endl;
            // cerr << (1 - ss[n - i - 1]) << endl;
            E[i] = (1 - p) + (p * (sum[n - i - 1] + s[n - i] / q * 2 * (n - i)));
            E[i] /= 1 - p;
            ans += E[i];
        }
        cout << ans << endl;
    }
}