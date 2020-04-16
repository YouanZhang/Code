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
vector <int> G[MAXN];
int in[MAXN], dis[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 2; i <= n; i++) dis[i] = INT_INF;
    queue <int> q;
    q.push(1); in[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop(); in[u] = 0;
        for (auto v : G[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                if (!in[v]) in[v] = 1, q.push(v);
            }
        }
    }
    cout << dis[n] - 1 << endl;
    return 0;
}