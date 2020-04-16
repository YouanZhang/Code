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
LL a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n; cin >> n;
        LL ans = 0;
        cin >> a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            if (a[i] >= a[i - 1]) continue;
            LL cnt = 0;
            for (LL x = a[i - 1] - a[i]; x; x >>= 1) cnt++;
            ans = max(ans, cnt);
            a[i] = a[i - 1];
        }
        cout << ans << endl;
    }
    return 0;
}