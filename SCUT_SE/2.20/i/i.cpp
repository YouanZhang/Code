#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int_fast64_t a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(8); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    DB ans = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > i) {
            cout << -1 << endl;
            return 0;
        }
        else ans = min(ans, a[i] * 1.0 / i);
    }
    cout << ans << endl;
    return 0;
}