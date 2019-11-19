#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN], n, m;
P h[MAXN];
void doit() {
    int ans = 0;
    for (int i = 1, j = m, s = 0; i <= n; i++) {
        if (h[m].first < a[i]) {
            cout << -1 << endl;
            return;
        }
        if (h[j].first < a[i]) {
            s = 0;
            ans++;
            j = m;
            i--;
            continue;
        }
        s++;
        if (h[j].second < s) i--, j--;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> h[i].first >> h[i].second;
        sort(h + 1, h + 1 + m);
        doit();
    }
    return 0;
}