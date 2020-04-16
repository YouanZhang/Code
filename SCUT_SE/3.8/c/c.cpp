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
        LL n; cin >> n;
        LL ans = 1;
        for (LL i = 2; i <= sqrt(n) + 1; i++) 
            for (; n % i == 0; n /= i) ans += i - 1;
        ans += n - 1;
        cout << ans << endl;
    }
    return 0;
}