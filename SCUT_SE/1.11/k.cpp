#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL x, y;
    cin >> x >> y;
    LL a = (x + y) / 2;
    LL b = (x - y) / 2;
    cout << a * b << endl;
}