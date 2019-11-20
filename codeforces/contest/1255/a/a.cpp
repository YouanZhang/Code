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
int x[10];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    cin >> ca;
    x[1] = x[2] = x[5] = 1;
    x[3] = x[4] = 2;
    for (; ca; ca--) {
        int a, b, d;
        cin >> a >> b;
        d = abs(a - b);
        cout << d / 5 + x[d % 5] << endl;
    }

    return 0;
}