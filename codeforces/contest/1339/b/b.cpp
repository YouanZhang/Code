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
int a[MAXN], ans[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = 1, l = 1, r = n; i <= n; i++) {
            if (i & 1) {
                ans[i] = a[l];
                if (++l == r + 1) break;
            }
            else {
                ans[i] = a[r];
                if (--r == l - 1) break;
            }
        }
        for (int i = n; i; i--) cout << ans[i] << ' '; cout << endl;
    }
    return 0;
}