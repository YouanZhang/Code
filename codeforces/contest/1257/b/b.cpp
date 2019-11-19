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
    int ca; 
    for (cin >> ca; ca; ca--) {
        int x, y;
        cin >> x >> y;
        bool ans = 0;
        if (x == 2 || x == 3) {
            if (y <= 3) ans = 1;
            else ans = 0;
        }
        else if (x == 1) ans = (y == 1);
        else ans = 1;
        cout << (ans == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}