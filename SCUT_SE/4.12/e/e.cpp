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
int a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, k; cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; i++) cout << i << ' '; cout << endl;
        return 0;
    }
    if (k == n) {
        for (int i = 1; i <= n; i++) cout << 2 - (i & 1) << ' '; cout << endl;
        return 0;
    }
    int lim = ceil(n * 1.0 / k);
    if (k & 1) {
        for (int i = 1; i <= k; i++) a[i] = (i & 1) ^ 1;
    }
    else {
        a[1] = 0; a[2] = 2;
        for (int i = 3; i <= k; i++) a[i] = (i & 1);
        lim = max(lim, 3);
    }
    for (int i = k + 1; i <= n; i++) a[i] = (a[i - k] + 1) % lim;
    for (int i = 1; i <= n; i++) cout << a[i] + 1 << ' '; cout << endl;
    return 0;
}