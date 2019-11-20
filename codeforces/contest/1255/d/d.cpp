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
string s[107];
char nam[107], ans[107][107];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (int i = 0; i < 10; i++) nam[i] = '0' + i;
    for (int i = 0; i <= 25; i++) nam[i + 10] = 'a' + i;
    for (int i = 0; i <= 25; i++) nam[i + 36] = 'A' + i;
    for (cin >> ca; ca; ca--) {
        int r, w, n, m = 0;
        cin >> r >> w >> n;
        for (int i = 0; i < r; i++) {
            cin >> s[i];
            for (int j = 0; j < w; j++) m += s[i][j] == 'R';
        }
        int les = n - m % n, mor = m % n, fod = m / n;
        int tagnam = 0, cntfod = fod;
        for (int i = 0; i < r; i++) {
            if (i & 1) {
                for (int j = w - 1; j >= 0; j--) {
                    if (tagnam == n) ans[i][j] = nam[tagnam - 1];
                    else ans[i][j] = nam[tagnam];
                    if (s[i][j] == '.') continue;
                    cntfod--;
                    if (cntfod == 0) {
                        tagnam++;
                        if (les == 0) mor--;
                        else les--;
                        cntfod = fod + (les == 0);
                    }
                }
            }
            else {
                for (int j = 0; j < w; j++) {
                    if (tagnam == n) ans[i][j] = nam[tagnam - 1];
                    else ans[i][j] = nam[tagnam];
                    if (s[i][j] == '.') continue;
                    cntfod--;
                    if (cntfod == 0) {
                        tagnam++;
                        if (les == 0) mor--;
                        else les--;
                        cntfod = fod + (les == 0);
                    }
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < w; j++) cout << ans[i][j];
            cout << endl;
        }
    }
    return 0;
}