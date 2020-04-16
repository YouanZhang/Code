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
const int MOD = 998244353;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, k; cin >> n >> k;
    cout << (2 * n - k + 1) * k / 2 << ' ';
    LL a; LL ans = 1;
    for (int last = 0, i = 1; i <= n; i++) {
        cin >> a;
        if (a > n - k) {
            if (last != 0) ans = ans * (i - last) % MOD;
            last = i;
        }
    }
    cout << ans << endl;
    return 0;
}