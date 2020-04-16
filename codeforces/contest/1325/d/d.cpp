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
    LL u, v; cin >> u >> v;
    if (u == v) {
        if (u == 0) cout << 0 << endl;
        else cout << 1 << endl << u << endl;
        return 0;
    }
    LL x = v - u;
    if (x < 0 || (x & 1)) cout << -1 << endl;
    else {
        x = x / 2;
        if (x + u == (x ^ u)) {
            cout << 2 << endl << x << ' ' << x + u << endl;
        }
        else {
            cout << 3 << endl << x << ' ' << x << ' ' << u << endl;
        }
    }
    return 0;
}