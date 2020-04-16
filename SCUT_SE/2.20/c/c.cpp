#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <DB, DB> P;
typedef pair <int, P> PP;
const int MAXN = 1e3+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
struct node {
    int id;
    DB x, y;
    DB l, r;
    node(int _id, DB _x, DB _y, DB _l, DB _r):id(_id), x(_x), y(_y), l(_l), r(_r){}
};
vector<int> G[MAXN];
P ans[MAXN];
bool vis[MAXN];
int n, cnt;
void dfs(int x, int f) {
	for(auto y : G[x]) {
		if(y == f) continue;
		ans[y] = P(ans[x].first + cos(cnt * PI / n), ans[x].second + sin(cnt * PI / n));
		cnt++;
		dfs(y, x);
	}
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(8); cout << fixed;
    cin >> n; 
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
	dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}