#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
vector <int> a[MAXN];
int pos[MAXN];
int main() {
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    for (int i = 1, las, cur; i <= m; i++) {
        las = cur;
        cin >> cur;
        if (i == 1) continue;
        a[las].push_back(cur);
        a[cur].push_back(las);
        ans += abs(las - cur);
    }
    cout << ans;
    for (int i = 1; i <= n; i++) pos[i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < a[i - 1].size(); j++)
            if (a[i - 1][j] != i) ans -= abs(pos[i - 1] - pos[a[i - 1][j]]);
        for (int j = 0; j < a[i].size(); j++)
            if (a[i][j] != i - 1) ans -= abs(pos[i] - pos[a[i][j]]);
        pos[i - 1] = i;
        pos[i] = 1;
        for (int j = 0; j < a[i - 1].size(); j++)
            if (a[i - 1][j] != i) ans += abs(pos[i - 1] - pos[a[i - 1][j]]);
        for (int j = 0; j < a[i].size(); j++)
            if (a[i][j] != i - 1) ans += abs(pos[i] - pos[a[i][j]]);
        cout << ' ' << ans;
    }
    cout << endl;
}