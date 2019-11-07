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
int J(int n, int m) {
    if (m == 1) return n - 1;
    int ans = 0;
    for (int i = 2; i <= n; ) {
        if (ans + m >= i) {
            ans = (ans + m) % i;
            i++;
            continue;
        }
        int step = (i - 1 - ans - 1) / (m - 1);
        if (i + step > n) {
            ans += (n - (i - 1)) * m;
            break;
        }
        i += step; ans += step * m;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    for (int n, m; cin >> n >> m; ) cout << J(n, m) << endl;
    return 0;
}