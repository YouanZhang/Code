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
LL qp(LL a, LL b) {
    LL ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int x; cin >> x;
    for (int i = 1; i <= x; i++) {
        LL n; cin >> n;
        LL a = (n - 1) % MOD * qp(2, n) % MOD;
        LL b = 2 * (3 - n) % MOD;
        LL c = (qp(2, n) - 4 + MOD) % MOD * 2 % MOD;
        LL d = (n - 1) % MOD;
        cout << (a - b - c - d + 3LL * MOD) % MOD << endl;
    }
    return 0;
}