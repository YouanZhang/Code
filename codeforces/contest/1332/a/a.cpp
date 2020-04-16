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
int a[4];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int x0, x1, x2, y0, y1, y2;
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
        if (a[0] != a[1]) 
            x0 += a[1] - a[0];
        else if (a[0] && x0 == x1 && x1 == x2) {
            cout << "No" << endl;
            continue;
        }
        if (a[2] != a[3])
            y0 += a[3] - a[2];
        else if (a[2] && y0 == y1 && y1 == y2) {
            cout << "No" << endl;
            continue;
        }
        if (x1 <= x0 && x0 <= x2 && y1 <= y0 && y0 <= y2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}