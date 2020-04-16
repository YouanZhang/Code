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
int a[107], f[107][107][2];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    int cnt0 = n / 2, cnt1 = n / 2;
    if (n & 1) cnt1++;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0 && (a[i] & 1)) cnt1--;
        if (a[i] != 0 && !(a[i] & 1)) cnt0--;
    }
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
                if (a[i] & 1) {
                    f[i][0][1] = f[i - 1][0][1];
                    f[i][0][0] = INT_INF;
                }
                else {
                    f[i][0][0] = f[i - 1][0][1] + 1;
                    f[i][0][1] = INT_INF;
                }
            for (int j = 1; j <= min(cnt0, m); j++){ 
                if (a[i] & 1) {
                    f[i][j][1] = min(f[i - 1][j][0] + 1, f[i - 1][j][1]);
                    f[i][j][0] = INT_INF;
                }
                else {
                    f[i][j][0] = min(f[i - 1][j][1] + 1, f[i - 1][j - 1][0]);
                    f[i][j][1] = INT_INF;
                }
            }
        }
        else {
            m++;
            f[i][0][0] = INT_INF;
            f[i][0][1] = f[i - 1][0][1];
            for (int j = 1; j <= min(cnt0, m); j++) {
                f[i][j][0] = min(f[i - 1][j][1] + 1, f[i - 1][j - 1][0]);
                f[i][j][1] = min(f[i - 1][j][0] + 1, f[i - 1][j][1]);
            }
        }
    }
    cout << min(f[n][cnt0][0], f[n][cnt0][1]) << endl;
    return 0;
}