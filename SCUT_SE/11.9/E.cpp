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
struct dat{
    LL a;
    int id;
}a[MAXN];
bool cmp(dat a, dat b) {
    return abs(a.a) < abs(b.a);
}
int ans[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, Ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        ans[a[i].id] = a[i].a >= 0 ? 1 : -1;
        ans[a[i].id] *= (1 << (i - 1));
        Ans += ans[a[i].id] * a[i].a;
    }
    cout << Ans << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}