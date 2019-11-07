#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 7;
const int LMT = 3;
const LL MOD = 1e9 + 7;
LL f[2][LMT + 7][4];
struct My {
    int first, second, id, ans;
}a[MAXN];
bool cmpfirst(My a, My b) {return a.first < b.first;}
bool cmpid(My a, My b) {return a.id < b.id;}
int main() {
    int n = 0;
    for (; cin >> a[++n].first >> a[n].second; ) a[n].id = n;
    n--;
    sort(a + 1, a + 1 + n, cmpfirst);
    for (int i = 0; i <= LMT; i++) f[0][i][3] = 1; 
    f[1][0][3] = 1;
    for (int i = 1, k = 1; i <= LMT; i++) {
        for (int j = 1; j <= LMT; j++) {
            if (i == 1 && j == 1) {
                f[i][j][3] = 1;
                continue;
            }
            //0
            for (int u = 0; u < 4; u++)
                for (int v = 0; v < 4; v++) {
                    f[i & 1][j][0] += f[(i & 1) ^ 1][j][u] * f[(i & 1)][j - 1][v] % MOD;
                    f[i & 1][j][0] %= MOD;
                }
            //1
            f[i & 1][j][1] = f[(i & 1) ^ 1][j][1] * f[(i & 1)][j - 1][3] % MOD + f[(i & 1) ^ 1][j][3] * f[(i & 1)][j - 1][1] % MOD + f[(i & 1) ^ 1][j][1] * f[(i & 1)][j - 1][1] % MOD + f[(i & 1) ^ 1][j][3] * f[(i & 1)][j - 1][3] % MOD;
            f[i & 1][j][1] %= MOD;
            //2
            f[i & 1][j][2] = f[(i & 1) ^ 1][j][2] * f[(i & 1)][j - 1][3] % MOD + f[(i & 1) ^ 1][j][3] * f[(i & 1)][j - 1][2] % MOD + f[(i & 1) ^ 1][j][2] * f[(i & 1)][j - 1][2] % MOD + f[(i & 1) ^ 1][j][3] * f[(i & 1)][j - 1][3] % MOD;
            f[i & 1][j][1] %= MOD;
            //3
            f[i & 1][j][3] = f[(i & 1) ^ 1][j][3] * f[(i & 1)][j - 1][3] % MOD;
            f[i & 1][j][3] %= MOD;
        }
        while (i == a[k].first) {
            a[k].ans = f[i & 1][a[k].second][0] + f[i & 1][a[k].second][1] + f[i & 1][a[k].second][2] + f[i & 1][a[k].second][3];
            k++;
        }
        if (k > n) break;
    }
    sort(a + 1, a + 1 + n, cmpid);
    for (int i = 1; i <= n; i++) cout << a[i].ans << endl;
}