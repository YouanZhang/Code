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
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << endl << 1 << endl;
    }
    else if (n == 3) {
        cout << 2 << endl << 1 << ' ' << 3 << endl;
    }
    else if (n == 4) {
        cout << 4 << endl << 3 << ' ' << 1 << ' ' << 4 << ' ' << 2 << endl;
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; i += 2) cout << i << ' ';
        for (int i = 2; i <= n; i += 2) cout << i << ' ';
        cout << endl;
    }
    return 0;
}