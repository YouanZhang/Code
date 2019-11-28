#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
LL n, m, k, t;
LL a[MAXN];
struct My{
    LL l, r, d;
}trap[MAXN];
bool cmp(My a, My b) {return a.d > b.d;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> k >> m >> t; 
    t -= k + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    LL mxd = 0;
    for (int i = 1; i <= m; i++) {
        cin >> trap[i].l >> trap[i].r >> trap[i].d;
        if (trap[i].r * 2 > t) mxd = max(mxd, trap[i].d);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= mxd) ans++;
    }
    //sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= m; i++) cin >> trap[i].l >> trap[i].r >> trap[i].d;
    // sort(trap + 1, trap + 1 + m, cmp); trap[m + 1].d = 0;
    // LL mxr = 0, mnd = trap[1].d;
    // for (int i = 1; i <= m; i++) {
    //     mxr = max(mxr, trap[i].r);
    //     if (mxr * 2 > t) break;
    //     mnd = trap[i + 1].d;
    // }
    // LL ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (a[i] >= mnd) ans++;
    // }
    cout << ans << endl;
    return 0;
}