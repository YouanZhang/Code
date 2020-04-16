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
int qpow(int a, int b){
    int ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret *= a;
        a *= a;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n; cin >> n;
        vector <P> a;
        for (int i = 2; i <= sqrt(n) + 1; i++) {
            if (n % i == 0) {
                P p = P(i, 0);
                for (; n % i == 0; n /= i) p.second++;
                a.push_back(p);
            }
        }
        if (n != 1) a.push_back(P(n, 1));
        if (a.size() == 1) {
            if (a[0].second >= 6) {
                cout << "YES" << endl;
                cout << a[0].first << ' ' << qpow(a[0].first, 2) << ' ' << qpow(a[0].first, a[0].second - 3) << endl;
            }
            else cout << "NO" << endl;
        }
        else if (a.size() == 2) {
            P x = a[0], y = a[1];
            if (x.second > y.second) swap(x, y);
            if (x.second == 2 && y.second == 2) {
                cout << "YES" << endl;
                cout << x.first << ' ' << y.first << ' ' << x.first * y.first << endl;
            }
            else if (y.second >= 3) {
                cout << "YES" << endl;
                cout << qpow(x.first, x.second) << ' ' << y.first << ' ' << qpow(y.first, y.second - 1) << endl;
            }
            else cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << qpow(a[0].first, a[0].second) << ' ' << qpow(a[1].first, a[1].second) << ' ';
            int x = 1;
            for (int i = 2; i < a.size(); i++) {
                x = x * qpow(a[i].first, a[i].second);
            }
            cout << x << endl;
        }
    }
    return 0;
}