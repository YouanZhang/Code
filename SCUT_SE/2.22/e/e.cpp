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
LL a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    string s; cin >> s;
    LL m; cin >> m;
    LL n = s.size();
    LL ans = 0;
    for (LL i = 0; i < n; i++) a[i] = -1;
    for (LL i = 0; i < n; i++) {
        if (s[i] == 'E') {
            a[i] = i;
            for (LL j = (i - 1 + n) % n; s[j] != 'E'; j = (j - 1 + n) % n) a[j] = i;
        }
    }
    for (LL i = 0; i < n; i++) {
        if (a[i] != -1) 
            ans += max(0ll, m - (a[i] - i + n) % n);
    }
    cout << ans << endl;
    return 0;
}