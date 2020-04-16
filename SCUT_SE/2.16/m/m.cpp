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
        DB b1, b2, p1, p2;
        cin >> b1 >> p1 >> b2 >> p2;
        if (b1 * b2 == 0) {
            if (b1 == 0 && b2 == 0) cout << "Lazy" << endl;
            else if (b2 == 0) cout << "HaHa" << endl;
            else cout << "Congrats" << endl;
            continue;
        }
        if (abs(p1 * log(b1) - p2 * log(b2)) < EPS) cout << "Lazy" << endl;
        else if (p1 * log(b1) - p2 * log(b2) > EPS) cout << "HaHa" << endl;
        else cout << "Congrats" << endl;
    }
    return 0;
}