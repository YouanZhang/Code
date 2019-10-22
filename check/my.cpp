#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 7;
const LL MOD = 1e9 + 7;
LL sum[MAXN], p[MAXN];
int main() {
    freopen("in.txt", "r", stdin);
    for (LL n; cin >> n; ) {
        string s;
        cin >> s;
        p[n - 1] = 1; sum[0] = s[0] - '0';
        for (int i = n - 2; i >= 0; i--) p[i] = p[i + 1] * 10 % MOD;
        for (int i = 1; i < n; i++)
            sum[i] = s[i] - '0',
            sum[i] += sum[i - 1];
        LL ans = 0, cur = 0;
        for (LL i = 0; i < (n + 1) / 2; i++) {
            (cur += (sum[n - 1 - i] - (i == 0 ? 0 : sum[i - 1])) % MOD) %= MOD;
            (ans += cur * (p[i] + (i == n - 1 - i ? 0 : p[n - 1 - i])) % MOD) %= MOD;
            (ans += (i * (i + 1) / 2 % MOD+ (n - 1 - i) * (n - i) / 2 % MOD) % MOD * ((s[i] - '0') * p[i] % MOD + (i == n - 1 - i ? 0 : (s[n - 1 - i] - '0') * p[n - i - 1] % MOD)) % MOD) %= MOD;
        }
        cout << ans % MOD << endl;
    }
}