#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e7+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
LL f[MAXN][8];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }
    f[1][0] = f[1][3] = f[1][6] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 8; j++) f[i][j] = (f[i][j] + f[i - 1][7 - j]) % MOD;
        f[i][3] = (f[i][3] + f[i - 1][7]) % MOD;
        f[i][6] = (f[i][6] + f[i - 1][7]) % MOD;
        f[i][7] = (f[i][7] + f[i - 1][3] + f[i - 1][6]) % MOD;
    }
    cout << f[n][7] << endl;
    return 0;
}