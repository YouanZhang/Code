#include <bits/stdc++.h>
using namespace std;
int a[3];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    for (cin >> n; n; cin >> n) {
        a[1] = a[2] = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            int x;
            cin >> s >> x;
            if (s[0] == 'D') {
                a[1] += x;
                cout << "DROP " << 1 << ' ' << x << endl;
            }
            else {
                int m = a[1] - x;
                cout << "MOVE " << 1 << "->" << 2 << ' ' << a[1] << endl;
                cout << "TAKE " << 2 << ' ' << x << endl;
                if (m != 0) {
                    cout << "MOVE " << 2 << "->" << 1 << ' ' << m << endl;
                    a[1] = m;
                }
                else {
                    a[1] = 0;
                }
            }
        }
        cout << endl;
    }
}