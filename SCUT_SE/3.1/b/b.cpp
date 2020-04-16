#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <LL, LL> P;
typedef pair <int, P> PP;
const int MAXN = 200000;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
P p[MAXN];
LL calc(P a, P b, P c) {
    P A = P (a.first - b.first, a.second - b.second);
    P B = P (a.first - c.first, a.second - c.second);
    return abs(A.first * B.second - A.second * B.first);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
    LL ans = min(calc(p[n - 1], p[n], p[1]), calc(p[1], p[2], p[n]));
    for (int i = 1; i <= n - 2; i++) ans = min(ans, calc(p[i], p[i + 1], p[i + 2]));
    cout << ans << endl;
    return 0;
}