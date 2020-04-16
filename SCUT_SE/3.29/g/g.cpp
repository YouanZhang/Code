#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-3;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
char doit() {
    char a;
    string s; cin >> s;
    int sum = 'A' + 'B' + 'C' + 'D';
    DB d, l; cin >> d >> l;
    d = d / 180.0 * PI;
    DB x = l * cos(d), y = l * sin(d);
    int f = ((int) ceil(y / sqrt(3) * 2.0));
    DB liml = y / sqrt(3), limr = f - liml;
    DB curx = x;
    int cnt = 0;
    for (; curx - 1 - liml > EPS; curx -= 1) cnt++;
    if (f & 1) {
        if (cnt & 1) {
            if (limr - curx > EPS) a = s[1];
            else a = s[0];
        }
        else {
            if (limr - curx > EPS) a = sum - 'A' - s[0] - s[1];
            else a = 'A';
        }
    }
    else {
        if (cnt & 1) {
            if (limr - curx > EPS) a = 'A';
            else a = sum - 'A' - s[0] - s[1];
        }
        else {
            if (limr - curx > EPS) a = s[0];
            else a = s[1];
        }
    }
    cerr << a << endl;
    return a;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    if (doit() == doit()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}