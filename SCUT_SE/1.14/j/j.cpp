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
int n;
vector <P> G[MAXN];
LL dp[MAXN], cnt[MAXN], deg[MAXN], p[MAXN];
void DP(int u, int faw) {
    int ans = 1;
    for (auto i : G[u]) {
        int v = i.first;
        int w = i.second;
        if (w != 0) cnt[u]++, cnt[v]++;
        DP(v, w);
    }
    for (auto i : G[u]) {
        int v = i.first;
        int w = i.second;
        if (w == 0) ans = ans * (4 + (u == 1) - cnt[v]) % MOD * dp[v] % MOD;
        else ans = ans * dp[v] % MOD;
    }
    dp[u] = ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[i].push_back(P(v, w));
    }
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 5) {
            cout << 0 << endl;
            return 0;
        }
        for (int j = 1; j < 6; j++) p[i] = 0;
        for (auto j : G[i]) p[j.second]++;
        for (int j = 1; j < 6; j++) 
            if (p[j] > 1) {
                cout << 0 << endl;
                return 0;
            }
    }
    DP(1, 0);
    cout << dp[1] << endl;
    return 0;
}