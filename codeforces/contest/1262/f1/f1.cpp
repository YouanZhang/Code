#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2007;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 998244353;
int h[MAXN];
LL C[MAXN][MAXN];
LL qp(LL a, LL b) {
    LL ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD; 
    }
    return ret;
}
LL inv(LL x) {
    return qp(x, MOD - 2);
}
void getC(LL n, LL m) {
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, k, m = 0, ans = 0;
    cin >> n >> k;
    getC(n, n);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < n; i++) m += h[i] == h[i + 1];
    m += h[1] == h[n];
    m = n - m;
    ans = qp(k, n - m);
    LL s = 0;
    for (LL p = 1; p <= m; p++) {
        LL sum = 0;
        if (p & 1) sum = qp(2, p - 1);
        else sum = (qp(2, p - 1) + MOD - C[p][p / 2] * inv(2)) % MOD; 
        //for (int q = p; q >= p / 2 + 1; q--) sum = (sum + C[p][q]) % MOD;
        s = (s + sum * C[m][p] % MOD * qp(k - 2, m - p) % MOD) % MOD;
    }
    ans = ans * s % MOD;
    cout << ans << endl;
    return 0;
}