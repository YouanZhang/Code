#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <LL, LL> P;
typedef pair <LL, P> PP;
const LL MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const LL LL_INF = 1e9 + 7;
const LL MOD = 1e9 + 7;
vector <LL> G[MAXN]; 
vector <LL> node;
LL dfs(LL u, LL fa, LL dep) {
    LL son = 0;
    for (auto v : G[u]) {
        if (v == fa) continue;
        son += dfs(v, u, dep + 1);
    }
    node.push_back(dep - son);
    return son + 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, k;
    cin >> n >> k;
    for (LL i = 1; i < n; i++) {
        LL u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, 0);
    sort(node.begin(), node.end(), greater <LL> ());
    LL ans = 0;
    for (LL i = 0; i < k; i++) {
        ans += node[i];
    }
    cout << ans << endl;
    return 0;
}