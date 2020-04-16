#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e6;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
LL sum[MAXN + 7], ans[MAXN + 7];
int main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    // time_t st = clock();
    for (LL i = 1; i <= MAXN; i++)
        for (LL j = 2; i * j <= MAXN; j++) 
            sum[i * j] += i;
    // cerr << clock() - st << endl;
    LL tag = -1;
    for (LL i = 1; i <= MAXN; i++) {
        if (i == sum[i]) tag = i;
        ans[i] = tag;
    }
    // cerr << clock() - st << endl;
    LL n, x;
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        scanf("%lld", &x);
        // cout << ans[x] << endl;
        printf("%lld\n", ans[x]);
    }
    return 0;
}