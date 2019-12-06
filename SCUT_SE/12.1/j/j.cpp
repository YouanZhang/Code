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
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n; i += 2) {
        LL cnt = 0;
        for (LL p = 1; i * p <= n; p *= 2) cnt++;
        for (LL p = 2 - (cnt & 1); i * p <= n; p *= 4) ans += i * p;
    }
    cout << ans << endl;
    return 0;
}