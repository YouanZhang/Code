#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e7 + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e4 + 7;
LL n, a, b;
LL sl1(LL a, LL b, LL n) {
    vector <int> f;
    f.push_back(1);
    for (int i = 1; i <= n; i++) {
        f.push_back(0);
        if (i - a >= 0) f[i] += f[i - a];
        if (i - b >= 0) f[i] += f[i - b];
        f[i] %= MOD;
    }
    return f[n];
}
LL qp(LL a, LL b) {
    LL ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}
LL gcd(LL a, LL b) {return (b == 0 ? a : gcd(b, a % b));}
LL sl2() {
    LL _gcd = gcd(a, b);
    LL _lcm = a * b / _gcd;
    return qp(sl1(a, b, _lcm), n / _lcm - 1) * sl1(a, b, n % _lcm + _lcm) % MOD;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> a >> b;
    cout << sl1(a, b, n) << endl;
    return 0;
}