#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e3+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const LL MOD = 1e9 + 7;
LL f[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m;
    cin >> n >> m;
    LL ans = 0;
    for (int i = n; i >= 1; i--)
        for (int j = i; j <= n; j++) {
            f[i][j] = 1;
        }
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = n; k >= j; k--) {
                f[j][k] += f[j - 1][k] + f[j][k + 1] - f[j - 1][k + 1];
                f[j][k] %= MOD;
            }
        }
    }
    for (int i = n; i >= 1; i--)
        for (int j = i; j <= n; j++) {
            ans = (ans + f[i][j]) % MOD;
        }
    cout << ans << endl;
    return 0;
}