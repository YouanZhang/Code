#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 0;
const DB EPS = 1e-7;
const DB INF = 1e9;
DB a, b, c, d, L, R;
DB f(DB x) {
    return pow(x, a / x - x);
}
DB simpson(DB l, DB r) {
    return (f(l) + f(r) + 4 * f((l + r) / 2)) * (r - l) / 6;
}
DB integral(DB l, DB r, DB eps, DB sima) {
    DB mid = (l + r) / 2;
    DB siml = simpson(l, mid), simr = simpson(mid, r);
    if (fabs(simr + siml - sima) <= 15 * eps) return siml + simr + (siml + simr - sima) / 15;
    return integral(l, mid, eps / 2, siml) + integral(mid, r, eps / 2, simr);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(5); cout << fixed;
    cin >> a;
    DB L = EPS, R = 20;
    if (a < 0) cout << "orz" << endl;
    else cout << integral(L, R, EPS, simpson(L, R)) << endl;
    return 0;
}