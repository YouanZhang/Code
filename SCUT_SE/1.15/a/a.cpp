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
vector <P> T[MAXN];
LL t[MAXN], cnt[MAXN], sumt[MAXN], dis[MAXN], ans[MAXN];
int n;
void dfs1(int u, int fa) {
    cnt[u] = 1;
    sumt[u] = t[u];
    for (auto it : T[u]) {
        int v = it.first, w = it.second; 
        if (v == fa) continue;
        dis[v] = dis[u] + w;
        dfs1(v, u);
        cnt[u] += cnt[v];
        sumt[u] += sumt[v];
    }
}
void dfs2(int u, int fa, LL sum1, LL sum2) {
    ans[u] = t[u] * sum1 + sum2;
    for (auto it : T[u]) {
        int v = it.first, w = it.second; 
        if (v == fa) continue;
        dfs2(v, u, sum1 + w * (n - 2 * cnt[v]), sum2 + w * (sumt[1] - 2 * sumt[v]));
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> t[i];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        T[u].push_back(P(v, w));
        T[v].push_back(P(u, w));
    }
    dfs1(1, 0);
    LL sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += dis[i];
        sum2 += t[i] * dis[i];
    }
    dfs2(1, 0, sum1, sum2);
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}