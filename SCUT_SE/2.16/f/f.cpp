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
    LL ca;
    for (cin >> ca; ca; ca--) {
        LL n, k;
        cin >> n >> k;
        LL x = n - k;
        if (x % 6 == 0) cout << x / 6 << endl;
        else cout << x / 6 + 1 << endl;
    }
    return 0;
}