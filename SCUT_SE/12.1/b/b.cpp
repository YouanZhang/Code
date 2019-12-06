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
    for (LL i = 31622776; i < 100000000; ) {
        LL i2 = i * i;
        int j = 1;
        for (; j <= 16; j++) {
            if (j == 1 && i2 % 10 != 1) break;
            if (j == 13 && i2 % 10 != 1) break;
            if (j == 3 && i2 % 10 != 9) break;
            if (j == 5 && i2 % 10 != 2) break;
            if (j == 7 && i2 % 10 != 6) break;
            if (j == 9 && i2 % 10 != 0) break;
            if (j == 11 && i2 % 10 != 8) break;
            if (j == 15 && i2 % 10 != 7) break;
            i2 /= 10;
        }
        if (j == 17) {
            cout << i << endl;
            break;
        }
        i++;
    }
    return 0;
}