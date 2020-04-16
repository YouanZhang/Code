#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <LL, LL> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
string nam[107];
map <string, LL> mp;
vector <P> G[107];
LL dis[107], lin[107];
LL vis[107];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n, m; cin >> n >> m;
    n++; nam[1] = "English"; mp[nam[1]] = 1;
    for (LL i = 2; i <= n; i++) {
        cin >> nam[i];
        mp[nam[i]] = i;
    }
    for (LL i = 1; i <= m; i++) {
        string s, t; LL u, v, c; cin >> s >> t >> c;
        u = mp[s], v = mp[t];
        G[u].push_back(P(v, c)); G[v].push_back(P(u, c));
    }
    queue <LL> q1, q2; q2.push(1); vis[1] = 2;
    while (1) {
        if (q1.empty()) {
            if (q2.empty()) break;
            else while (!q2.empty()) q1.push(q2.front()), vis[q2.front()] = 1, q2.pop(); 
        }
        LL u = q1.front(); q1.pop();
        for (auto v : G[u]) {
            if (vis[v.first] == 0) {
                lin[v.first] = v.second;
                // dis[v.first] = dis[u] + v.second;
                q2.push(v.first); vis[v.first] = 2;
            }
            else if (vis[v.first] == 1) continue;
            else {
                lin[v.first] = min(lin[v.first], v.second);
            }
        }
    }
    LL ans = 0;
    for (LL i = 2; i <= n; i++) {
        if (!vis[i]) {
            cout << "Impossible" << endl;
            return 0;
        }
        ans += lin[i];
    }
    cout << ans << endl;
    return 0;
}