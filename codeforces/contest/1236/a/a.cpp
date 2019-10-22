#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (; n; n--) {
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        if (b >= c / 2) {
            ans += c / 2 * 3;
            b -= c / 2;
        }
        else {
            ans += b * 3;
            b -= b;
        }
        if (b / 2 >= a) ans += a * 3;
        else ans += b / 2 * 3;
        cout << ans << endl;
    }
    return 0;
}