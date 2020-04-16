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
DB s[MAXN];
int n, m;
DB getsum(int i, int x) {
    DB ret = 0;
    for (int y = 0; y <= x; y++) {
        int z = i - y;
        if (z <= 0) z += n;
        ret += s[z];
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(12); cout << fixed;
    cin >> n >> m;
    DB nn = n, mm = m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    if (m == 1) {
        for (int i = 1; i <= n; i++) cout << 100.0 / nn << ' ';
        cout << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        DB ans = 0;
        for (int x = 0; x <= n - m; x++) {
            DB sum = mm / nn;
            for (int y = 1; y <= x; y++) 
                sum *= ((nn - y) - (mm - 1)) / (nn - y);
            sum *= (mm - 1) / (nn - x - 1);
            sum *= getsum(i, x);
            ans += sum;
        }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}