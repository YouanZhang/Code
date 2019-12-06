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
string s[11];
int p[4][11];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            for (int j = 0; j < 4; j++) {
                p[j][s[i][j] - '0'] = 1;
            }
        }
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            int tag = 0;
            for (int j = 1; j < i; j++) {
                if (s[i] == s[j]) tag = j;
            }
            if (tag) {
                for (int j = 0; j < 10; j++) {
                    if (!p[0][j]) {
                        s[i][0] = j + '0';
                        p[0][j] = 1;
                        break;
                    }
                }
                ans++;
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) cout << s[i] << endl;
    }
    return 0;
}