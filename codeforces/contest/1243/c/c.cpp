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
    LL n; cin >> n; LL N = n;
    if (n < 3) {
        cout << n << endl;
        return 0;
    }
    queue <LL> q;
    for (LL i = 2; i <= sqrt(n) + 1; i++) {
        if (n % i == 0) q.push(i);
        for (;n % i == 0; n /= i);
    }
    if (n != 1) q.push(n);
    if (q.size() == 1) cout << q.front() << endl;
    else cout << 1 << endl;
    return 0;
}