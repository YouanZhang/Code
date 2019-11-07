#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL C(LL n, LL m) {
    if (m == 1) return n;
    else return (n - 1) * n / 2;
}
int main() {
    for (LL n, m; cin >> n >> m; ) {
        LL ans = 0;
        if (n == 1) {
            ans += 1;
            if (m >= 2) ans += 3;
            if (m >= 3) ans += 3 * C(m - 1, 2);
            ans %= MOD;
            cout << ans << endl;
            continue;
        }
        if (m == 1) {
            ans += 1;
            if (n >= 2) ans += 3;
            if (n >= 3) ans += 3 * C(n - 1, 2);
            ans %= MOD;
            cout << ans << endl;
            continue;
        }
        if (n >= 2 && m >= 2) {
            ans += 18 * C(n - 1, 1) * C(m - 1, 1) + 3 * C(n - 1, 1) + 3 * C(m - 1, 1) + 1;
            ans %= MOD;
        }
        if (n >= 3) {
            ans += 6 * C(n - 1, 2) * C(m - 1, 1);
            ans %= MOD;
        }
        if (m >= 3) {
            ans += 6 * C(n - 1, 1) * C(m - 1, 2);
            ans %= MOD;
        }
        if (n >= 3 && m >= 3) {
            ans += 4 * C(n - 1, 2) * C(m - 1, 2);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}