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
int n, m, K;
vector <int> fr[MAXN];
int fa[MAXN], ans[MAXN];
int getFa(int x) {
    return x == fa[x] ? x : fa[x] = getFa(fa[x]);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        fr[a].push_back(b);
        fr[b].push_back(a);
    }
    for (int i = 1; i <= K; i++) {
        int u, v;
        cin >> u >> v;
        int fu = getFa(u), fv = getFa(v);
        if (fu != fv) fa[fu] = fv;
    }
    for (int u = 1; u <= n; u++) {
        for (auto v : fr[u]) {
            ans[u] += getFa(u) == getFa(v);
        }
        fr[u].clear();
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        char c;
        cin >> c;
        if (c == '?') {
            int u;
            cin >> u;
            for (auto v : fr[u]) {
                ans[u] += getFa(u) == getFa(v);
            }
            fr[u].clear();
            cout << ans[u] << endl;
        }
    }
    return 0;
}