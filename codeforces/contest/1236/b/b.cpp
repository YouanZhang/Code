#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
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
    LL n, m;
    cin >> n >> m;
    cout << qp(qp(2, m) - 1, n) << endl;
    return 0;
}