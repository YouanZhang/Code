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
LL f[MAXN][2];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL l, k; cin >> l >> k;
    f[1][1] = f[k][1] = 1;
    LL ans = 0;
    for (int i = 2; i <= l; i++) {
        f[i][0] += f[i - 1][1];
        f[i][1] += f[i - 1][0];
        if (i - k > 0) f[i][1] += f[i - k][0];
    }
    for (int i = 1;i <= l; i++) 
        ans += f[i][1];
    cout << ans << endl;
    return 0;
}