#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 0;
const DB EPS = 1e-9;
DB a, b, c, d, L, R;
DB f(DB x) {
    return (c * x + d) / (a * x + b);
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
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> a >> b >> c >> d >> L >> R;
    cout << integral(L, R, EPS, simpson(L, R)) << endl;
    return 0;
}