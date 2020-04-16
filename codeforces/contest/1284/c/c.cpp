#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 250000+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
long long fac[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    long long n, mod;
    cin >> n >> mod;
    long long ans = 0;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i - 1] % mod;
    }
    for (int i = 1; i <= n; i++) {
        ans = ans + (n - i + 1) * (n - i + 1) % mod * fac[i] % mod * fac[n - i] % mod;
        ans %= mod;
    }
    cout << ans << endl;;
    return 0;
}