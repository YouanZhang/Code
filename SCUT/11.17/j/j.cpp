#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 507;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
string s[MAXN];
LL mp[MAXN][MAXN], cnt[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int step = 1; step < n; step++) {
        for (int i = 0; i + step < n; i++) {
            int j = i + step;
            if (i == 0 && j == 2) {
                int tag = 0;
            }
            for (int k = i + 1; k < j; k++) {
                cnt[i][j] += cnt[i][k] * mp[k][j];
                cnt[i][j] %= 10;
            }
            if ((cnt[i][j] + 1) % 10 == s[i][j] - '0') mp[i][j] = 1, cnt[i][j] ++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mp[i][j];
        cout << endl;
    }
    return 0;
}