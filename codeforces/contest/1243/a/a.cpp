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
int a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int T; 
    for (cin >> T; T ; T--) {
        int n; cin >> n;
        memset(a, 0, sizeof (a));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, min(a[i], n - i + 1));
        }
        cout << ans << endl;
    }
    return 0;
}