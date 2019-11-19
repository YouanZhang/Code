#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 7;
LL pl[MAXN], mi[MAXN], mo[MAXN];
int main() {
    LL n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        int co, fr, to;
        cin >> co >> fr >> to;
        // if (co > 0) pl[fr] += co, pl[to + 1] -= co;
        if (co < 0) mi[fr] += -co, mi[to + 1] -= -co;
        mo[to] += co;
    }
    mo[0] = s;
    for (int i = 1; i <= m; i++) {
        // pl[i] += pl[i - 1];
        mi[i] += mi[i - 1];
        mo[i] += mo[i - 1];
        if (mo[i - 1] - mi[i] < 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}