#include <bits/stdc++.h>
using namespace std;
typedef double DB;
typedef pair <DB, DB> P;
typedef pair <int, P> PP;
const int MAXN = 11;
const DB EPS = 1e-9;
const DB INF = 1e100;
vector <PP> G[MAXN];
DB dist[MAXN];
bool in[MAXN];
int n, m, T;
DB spfa(DB t) {
    for (int i = 1; i <= n; i++) dist[i] = INF, in[i] = 0;
    queue <int> q;
    dist[1] = 0; q.push(1); in[1] = 1;
    for (; !q.empty(); ) {
        int u = q.front(); q.pop(); in[u] = 0;
        for (auto it : G[u]) {
            int v = it.first;
            if (dist[u] + it.second.first * t + it.second.second < dist[v]) {
                dist[v] = dist[u] + it.second.first * t + it.second.second;
                if (in[v]) continue;
                in[v] = 1; q.push(v);
            }
        }
    }
    return dist[n];
}
DB simpson(DB l, DB r) {
    return (spfa(l) + spfa(r) + 4 * spfa((l + r) / 2)) * (r - l) / 6;
}
DB integral(DB l, DB r, DB eps, DB fa) {
    DB mid = (l + r) / 2;
    DB fl = simpson(l, mid), fr = simpson(mid, r);
    if (fabs(fl + fr - fa) <= 15 * eps) return fl + fr + (fl + fr - fa) / 15;
    return integral(l, mid, eps / 2, fl) + integral(mid, r, eps / 2, fr);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(8); cout << fixed;
    for (; cin >> n >> m >> T; ) {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            int a, b; DB c, d;
            cin >> a >> b >> c >> d;
            G[a].push_back(PP(b, P(c, d)));
        }
        cout << integral(0, T, EPS, simpson(0, T)) / T << endl;
    }
    return 0;
}