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
int q[MAXN], p[MAXN], ans[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) q[i] = p[i] = ans[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> q[i];
            p[q[i]] = 1;
        }
        bool flag = 0;
        for (int i = 1, j = 1; i <= n; i++) {
            if (q[i] > q[i - 1]) ans[i] = q[i];
            else {
                for (; p[j]; j++);
                if (j > q[i]) {
                    cout << -1 << endl;
                    flag = 1;
                    break;
                }
                ans[i] = j;
                p[j] = 1;
            }
        }
        if (flag) continue;
        for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << endl;
    }
    return 0;
}