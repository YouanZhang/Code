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
const int INT_INF = 2e9;
const int MOD = 1e9 + 7;
LL a[MAXN];
priority_queue <LL, vector <LL>, greater <LL> > len;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        int l = a[i] - a[i - 1] - 1;
        len.push(l / 2);
        len.push(l / 2 + (l & 1));
    }
    len.push(a[1] - (-INT_INF));
    len.push(INT_INF - a[n]);
    LL ans = 0, dism = 0, numdism = 0;
    for (int dis = 1; m; dis++) {
        while (len.top() < dis) len.pop();
        dism = dis;
        if (m >= len.size()) m -= len.size(), ans += len.size() * dis, numdism = len.size();
        else ans += m * dis, numdism = m, m = 0;
    }
    // cerr << dism << ' ' << numdism << endl;
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        int j;
        LL l, r;
        if (i == 1) l = a[i] - (-INT_INF);
        else l = a[i] - a[i - 1] - 1, l /= 2;
        for (j = 1; j <= min(dism, l); j++) cout << a[i] - j << ' ';
        if (j == dism + 1) numdism--;
        if (numdism == 0) dism--, numdism--;
        if (i == n) r = INT_INF - a[i];
        else r = a[i + 1] - a[i] - 1, r = r / 2 + (r & 1);
        for (j = 1; j <= min(dism, r); j++) cout << a[i] + j << ' ';
        if (j == dism + 1) numdism--;
        if (numdism == 0) dism--, numdism--;
    }
    cout << endl;
    return 0;
}