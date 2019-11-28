#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = (1 << 18) + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
LL a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n;
    cin >> n;
    LL tag = 0, p = 0;
    for (int i = n; i != 1; i >>= 1) p++;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            tag = i;
        }
    }
    sort(a + tag + 1, a + n);
    //for (int i = 0; i < n; i++) cerr << a[i] << ' '; cerr << endl;
    LL ans = 0;
    LL q = 0;
    for (int i = tag + 1; i != 1; i >>= 1) q++;
    for (int i = tag + 1; i <= n && i <= tag + p - q; i++) ans += a[i];
    cout << ans << endl;
    return 0;
}