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
LL qp(LL a, LL b) {
    LL ret = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}
LL inv(LL x) {
    return qp(x, MOD - 2);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, m; cin >> n >> m;
    LL ans = 1;
    for (int i = 1; i <= n - 1; i++) ans = ans * i % MOD;
    for (int i = 1; i <= m - n + 1; i++) ans = ans * i % MOD;
    ans = inv(ans);
    for (int i = 1; i <= m; i++) ans = ans * i % MOD;
    ans = ans * (n - 2) % MOD * qp(2, n - 3) % MOD;
    cout << ans << endl;
    return 0;
}