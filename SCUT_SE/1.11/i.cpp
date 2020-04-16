#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(3); cout << fixed;
    int n;
    for (; cin >> n; ) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int x = s[s.size() - 1] - '0';
            if (x >= 5) ans += 10 - x;
            else ans += -x;
        }
        cout << 1.0 * ans / 1000 << endl;
    }
}