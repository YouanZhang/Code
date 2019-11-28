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
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, a, b, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> k;
        if (b < a) swap(a, b);
        if (b % a == 0) {
            if (b / a - 1 >= k) cout << "REBEL" << endl;
            else cout << "OBEY" << endl;
        }
        else {
            LL c = gcd(a, b);
            if ((b - c) % a == 0) {
                if ((b - c) / a >= k) cout << "REBEL" << endl;
                else cout << "OBEY" << endl;
            }
            else {
                if ((b - c) / a + 1 >= k) cout << "REBEL" << endl;
                else cout << "OBEY" << endl;
            }
        }
    }
    return 0;
}