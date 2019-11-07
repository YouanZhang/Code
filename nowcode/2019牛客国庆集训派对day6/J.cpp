#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int p[MAXN], d[MAXN];
int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> p[i];
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            ans += min(p[a], p[b]);
        }
        cout << ans << endl;
    }
}