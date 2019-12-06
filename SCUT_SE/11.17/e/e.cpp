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
vector <int> G[MAXN];
int c[MAXN], d[MAXN], f[MAXN];
void dfs(int fa, int u) {
    f[u] = fa;
    for (auto v : G[u] ) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfs(u, v);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) cin >> c[i];
    dfs(0, c[1]);
    int mx = 0, mxid = 1;
    for (int i = 1; i <= m; i++)
        if (d[c[i]] > mx) mx = d[c[i]], mxid = c[i];
    if (mx & 1) {
        cout << "NO" << endl;
        return 0;
    }
    int ans = mxid;
    for (int i = mx; i != mx / 2; i--) ans = f[ans];
    dfs(0, ans);
    int dans = 0;
    for (int i = 1; i <= m; i++) {
        if (c[i] == ans) continue;
        if (!dans) {
            dans = d[c[i]];
            continue;
        }
        if (d[c[i]] != dans) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
}