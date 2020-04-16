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
int u[MAXN], v[MAXN], deg[MAXN], ans[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i];
        deg[u[i]]++; deg[v[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (deg[u[i]] == 1 || deg[v[i]] == 1) ans[i] = ++cnt;
    }
    for (int i = 1; i < n; i++) {
        if (ans[i] == 0) ans[i] = ++cnt;
        cout << ans[i] - 1 << endl;
    }
    return 0;
}