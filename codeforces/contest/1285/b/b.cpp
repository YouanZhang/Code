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
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        LL Y = 0;
        bool potag = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= 0) potag = 0; 
            Y += a[i];
        }
        LL s = 0, mx = -INT_INF, l = 1, r = 1;
        P ans = P(0, 0), cur = P(1, 0);
        for (int i = 1; i <= n; i++) {
            s += a[i]; cur.second++;
            if (s > mx) mx = s, ans = cur;
            if (s <= 0) s = 0, cur = P(i + 1, i);
        }
        if (Y == mx) {
            if (ans.first == 1 && ans.second == n) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if (Y > mx) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}