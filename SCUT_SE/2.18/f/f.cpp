#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <LL, LL> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
P p[MAXN];
DB cross(P A, P B) {
    return A.first * B.second - A.second * B.first;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    LL tot = 0;
        LL ans = 0;
    for (cin >> ca; ca; ca--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> p[i].first >> p[i].second;
        for (int i = 2; i <= n; i++) {
            ans += cross(p[i], p[i - 1]);
        }
        ans += cross(p[1], p[n]);
    }
    cout << abs(ans) / 2 << endl;
    return 0;
}