#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e3+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
P two[MAXN][MAXN], fiv[MAXN][MAXN];
P operator + (P a, P b) {
    return P(a.first + b.first, a.second + b.second);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    bool flag = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x == 0) flag = 1, two[i][j] = fiv[i][j] = P(100, 100);
            else {
                for (int k = x; k; k >>= 1) two[i][j].first += (k % 2 == 0);
                for (int k = x; k; k /= 5) two[i][j].second += (k % 5 == 0);
                fiv[i][j] = two[i][j];
            }
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (two[i - 1][j].first < two[i][j - 1].first) {
                two[i][j] = two[i][j] + two[i - 1][j];
                twonxt[i][j] = 1;
            }
            else {
                two[i][j] = two[i][j] + two[i][j - 1];
            }
            if (fiv[i - 1][j].second < fiv[i][j - 1].second) {
                fiv[i][j] = fiv[i][j] + fiv[i - 1][j];
                fivnxt[i][j] = 1;
            }
            else {
                fiv[i][j] = fiv[i][j] + fiv[i][j - 1];
            }
        }
    }
    int ans = min(min(two[n][n].first, two[n][n].second), min(two[n][n].first, two[n][n].second));
    if (flag) cout << min(1, ans) << endl;
    else cout << ans << endl;
    return 0;
}