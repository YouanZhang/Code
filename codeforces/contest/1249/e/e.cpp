#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5 + 7;
const DB EPS = 1e-9;
int f[MAXN][2], a[MAXN], b[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n >> f[0][1];
    cout << 0 << ' ';
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        f[i][0] = min(f[i - 1][0], f[i - 1][1]) + a[i];
        f[i][1] = min(f[i - 1][0] + f[0][1], f[i - 1][1]) + b[i];
        cout << min(f[i][0], f[i][1]) << ' ';
    }
    cout << endl;
    return 0;
}