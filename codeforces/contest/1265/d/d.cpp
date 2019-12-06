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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int B = b - (a - 1);
    int C = c - (d - 1);
    if (min(B, C) <= 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (B == C) {
        cout << "YES" << endl;
        for (int i = 1; i <= a; i++) cout << 0 << ' ' << 1 << ' ';
        for (int i = 1; i <= b - a; i++) cout << 2 << ' ' << 1 << ' ';
        cout << 2 << ' ';
        for (int i = 1; i <= d - 1; i++) cout << 3 << ' ' << 2 << ' ';
        cout << 3 << ' ';
        cout << endl;
        return 0;
    }
    if (B == C + 1) {
        cout << "YES" << endl;
        cout << 1 << ' ';
        for (int i = 1; i <= a; i++) cout << 0 << ' ' << 1 << ' ';
        cout << 2 << ' ';
        for (int i = 1; i <= c - d; i++) cout << 1 << ' ' << 2 << ' ';
        for (int i = 1; i <= d - 1; i++) cout << 3 << ' ' << 2 << ' ';
        cout << 3 << ' ';
        cout << endl;
        return 0;
    }
    if (C == B + 1) {
        cout << "YES" << endl;
        cout << 2 << ' ';
        for (int i = 1; i <= d; i++) cout << 3 << ' ' << 2 << ' ';
        cout << 1 << ' ';
        for (int i = 1; i <= b - a; i++) cout << 2 << ' ' << 1 << ' ';
        for (int i = 1; i <= a - 1; i++) cout << 0 << ' ' << 1 << ' ';
        cout << 0 << ' ';
        cout << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}