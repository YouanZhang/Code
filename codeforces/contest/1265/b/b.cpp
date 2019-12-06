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
int a[MAXN], p[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[a[i]] = i;
        }
        cout << 1;
        int l = p[1], r = p[1];
        for (int i = 2; i <= n; i++) {
            l = min(l, p[i]);
            r = max(r, p[i]);
            if (r - l + 1 == i) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}