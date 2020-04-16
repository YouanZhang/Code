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
P p[16], lid[16 * 16];
int f[1 << 16][16 * 16], mx[1 << 16], ans[1 << 16];
bool check(P a, P b, P c, P d) {
    P A = P (a.first - b.first, a.second - b.second);
    P B = P (c.first - d.first, c.second - d.second);
    if (A.first * B.second == A.second * B.first) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    int tot = (1 << n) - 1;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    int lno = 0;
    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) {
            f[(1 << i) ^ (1 << j)][++lno] = 0;
            lid[lno] = P (i, j);
        }
    for (int i = 0; i <= tot; i++) {
        int cnt = 0;
        for (int x = i; x; x >>= 1) cnt += (x & 1);
        for (int j = 1; j <= lno; j++) {
            if (f[i][j] == -1) continue;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) continue;
                for (int l = k + 1; l < n; l++) {
                    if (i & (1 << l)) continue;
                    if (check(p[lid[j].first], p[lid[j].second], p[k], p[l])) 
                        f[i ^ (1 << k) ^ (1 << l)][j] = max(f[i ^ (1 << k) ^ (1 << l)][j], f[i][j] + cnt / 2);
                }
            }
        }
    }
    for (int i = 0; i <= tot; i++) 
        for (int j = 1; j <= lno; j++) mx[i] = max(mx[i], f[i][j]);
    for (int i = 0; i <= tot; i++) 
        for (int j = i ^ tot; j; j = (j - 1) & (i ^ tot))
            ans[i ^ j] = max(ans[i ^ j], ans[i] + mx[j]);
    cout << ans[tot] << endl;
    return 0;
}