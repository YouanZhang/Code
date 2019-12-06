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
    LL n; cin >> n;
    for (int i = 1; i <= n; i++) {
        LL a[3];
        cin >> a[0] >> a[1] >> a[2];
        LL ans = 0;
        sort(a, a + 3);
        if (a[0] < a[2] - a[1]) ans = a[0] + a[1];
        else {
            ans = a[2] - a[1];
            a[0] -= a[2] - a[1];
            a[2] = a[1];
            if (a[0] & 1) a[0]--;
            ans += a[0];
            a[1] -= a[0] / 2;
            a[2] = a[1];
            ans += a[1];
        }
        cout << ans << endl;
    }
    return 0;
}