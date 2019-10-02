#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], b[MAXN];
bool f[MAXN], g[MAXN];
string s, t;
int main() {
    int q, n;
    for (cin >> q; q; q--) {
        cin >> n;
        cin >> s >> t;
        for (int i = 0; i < n; i++)
            a[i + 1] = s[i] - '0';
        for (int i = 0; i < n; i++)
            b[i + 1] = t[i] - '0';
        for (int i = 1; i <= n; i++) 
            f[i] = g[i] = 0;
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= 2) {
                if (f[i - 1]) f[i] = 1;
            }
            else if (g[i - 1] && b[i] > 2) f[i] = 1;
            if (b[i] <= 2) {
                if (g[i - 1]) g[i] = 1;
            }
            else if (f[i - 1] && a[i] > 2) g[i] = 1;
        }
        cout << (g[n] ? "YES" : "NO") << endl;
    }
}