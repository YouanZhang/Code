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
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(10); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
    DB r1, r2;
    cin >> r1 >> r2;
    DB t1 = atan2(r1, r1 + r2), t2 = PI / 2 - t1, t3 = PI - 2 * t2, t4 = PI / 2 - t3;
    cout << 0.5 * (r1 * (r1 + r2) - r1 * r1 * sin(t3) - t4 * r1 * r1 - t1 * r2 * r2) << endl;
    }
    return 0;
}