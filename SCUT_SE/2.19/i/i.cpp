#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e6+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN], b[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    int tag = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            tag = i;
            break;
        }
    }
    int l = tag, r = tag;
    for (int i = tag - 1; i; i--) {
        if (a[i] >= a[i + 1]) l = i;
        else break;
    }
    for (int i = tag + 1; i <= n; i++) {
        if (a[i] <= a[i - 1]) r = i;
        else break;
    }
    for (int i = l, j = r; i <= r; i++, j--)
        b[j] = a[i];
    bool ans = 1;
    for (int i = 2; i <= n; i++) {
        if (b[i] < b[i - 1]) {
            ans = 0;
            break;
        }
    }
    if (ans) cout << l << ' ' << r << endl;
    else cout << "impossible" << endl;
    return 0;
}