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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = 0;
    for (int i = 0; i + m <= n; i++) {
        char zero = 0, one = 0;
        bool flag = 1;
        for (int j = 0; j < m; j++) {
            if (t[j] - '0' == 0) {
                if (zero != 0 && zero != s[i + j]) {
                    flag = 0;
                    break;
                }
                else zero = s[i + j];
            }
            else {
                if (one != 0 && one != s[i + j]) {
                    flag = 0;
                    break;
                }
                else one = s[i + j];
            }
        }
        if (flag) {
            ans++;
            continue;
        }
        zero = 0, one = 0;
        flag = 1;
        for (int j = m - 1; j >= 0; j--) {
            if (t[j] - '0' == 0) {
                if (zero != 0 && zero != s[i + m - j - 1]) {
                    flag = 0;
                    break;
                }
                else zero = s[i + m - j - 1];
            }
            else {
                if (one != 0 && one != s[i + m - j - 1]) {
                    flag = 0;
                    break;
                }
                else one = s[i + m - j - 1];
            }
        }
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}