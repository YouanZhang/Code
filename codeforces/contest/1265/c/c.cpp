#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 4e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n < 10) {
            cout << 0 << ' ' << 0 << ' ' << 0 << endl;
            continue;
        }
        int lim = n / 2;
        for (; lim && a[lim] == a[lim + 1]; lim--);
        int g = 0, s = 0, b = 0;
        int i;
        for (i = 1; a[i] == a[1]; i++) g++;
        while (i < lim && s <= g) {
            s++;
            for (; i < lim && a[i + 1] == a[i]; i++) s++;
            i++;
        }
        b = lim - g - s;
        if (g < s && g < b) cout << g << ' ' << s << ' ' << b << endl;
        else cout << 0 << ' ' << 0 << ' ' << 0 << endl;
    }
    return 0;
}