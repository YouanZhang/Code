#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int MAXN = 1e5 + 7;
const int BASE = 131;
const LL MOD = 100280245065;
LL f[30];
char s[MAXN], t[MAXN];
unordered_map<LL, int> mp;
LL val[MAXN];
int len[MAXN];
int n, m, k, Ca, cnt;
LL getHash(char *s, int l, int r) {
    LL ans = 0;
    for (int i = l + 1; i <= r - 1; i++) {
        ans = (ans + f[s[i] - 'a' + 1]) % MOD;
    }
    ans *= 10000;
    ans += s[l] - 'a' + 1;
    ans += (s[r] - 'a' + 1) * 100;
    return ans;
}
int main() {
    scanf("%d", &Ca);
    f[0] = 1;
    for (int i = 1; i < 30; i++)
        f[i] = (f[i - 1] * BASE) % MOD;
    while (Ca--) {
        mp.clear();
        scanf("%s", s);
        m = strlen(s);
        scanf("%d", &n);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", t);
            len[i] = strlen(t);
            val[i] = getHash(t, 0, len[i] - 1);
            mp[val[i]] = 1;
        }
        sort(len, len + n);
        int size = unique(len, len + n) - len;
        for (int i = 0; i < size; i++) {
            LL now;
            for (int j = 0; j + len[i] - 1 < m; j++) {
                if (j == 0)
                    now = getHash(s, j, j + len[i] - 1);
                else {
                    now /= 10000;
                    if (len[i] > 2)
                        now = (now - f[s[j] - 'a' + 1] + f[s[j + len[i] - 2] - 'a' + 1] + 2 * MOD) % MOD;
                    now *= 10000;
                    now += s[j] - 'a' + 1;
                    now += (s[j + len[i] - 1] - 'a' + 1) * 100;
                }
                if (mp.find(now) != mp.end()) mp[now]++;
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", mp[val[i]] - 1);
    }
    return 0;
}