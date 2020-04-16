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
    int ca;
    for (cin >> ca; ca; ca--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            int ans = 0;
            for (cin >> x; x; x >>= 1)
                if (x & 1) ans++;
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}