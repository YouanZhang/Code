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
int a[MAXN], c[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n; cin >> n;
        int ans = 0;
        map <int, int> col;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 2; j <= (int) sqrt(a[i]) + 1; j++)
                if (a[i] % j == 0) {
                    if (col.find(j) == col.end()) col[j] = ++ans;
                    c[i] = col[j];
                    break;
                }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) cout << c[i] << ' ';
        cout << endl;
    }
    return 0;
}