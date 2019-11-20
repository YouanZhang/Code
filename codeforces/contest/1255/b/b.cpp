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
P a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int T;
    for (cin >> T; T; T--) {
        int n, m;
        cin >> n >> m;
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first; a[i].second = i;
            ans += 2 * a[i].first;
        }
        if (m < n || n == 2) {
            cout << -1 << endl;
            continue;
        }
        sort(a + 1, a + 1 + n);
        ans += (m - n) * (a[1].first + a[2].first);
        cout << ans << endl;
        for (int i = 1; i < n; i++) cout << i << ' ' << i + 1 << endl;
        cout << n << ' ' << 1 << endl;
        for (int i = 1; i <= m - n; i++) cout << a[1].second << ' ' << a[2].second << endl;
    }
    return 0;
}