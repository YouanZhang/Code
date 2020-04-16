#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e3+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n, m;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int movx[4] = {0, 0, -1, 1};
int movy[4] = {1, -1, 0, 0};
int ans;
bool isWall(int curx, int cury) {
    if (a[curx][cury] == '\\') return 1;
    if (curx + 1 <= n && cury + 1 <= m && a[curx + 1][cury + 1] == '\\') return 1;
    if (curx + 1 <= n && a[curx + 1][cury] == '/') return 1;
    if (cury + 1 <= m && a[curx][cury + 1] == '/') return 1;
    return 0;
}
void bfs(int curx, int cury, int z) {
    if (isWall(curx, cury)) return;
    queue <P> q;
    q.push(P(curx, cury)); vis[curx][cury] = 1;
    while (!q.empty()) {
        curx = q.front().first; cury = q.front().second; q.pop();
        if (isWall(curx, cury)) continue;
        if (curx - 1 >= 0 && cury - 1 >= 0 && a[curx][cury] == '.') {
            if (!vis[curx - 1][cury - 1]) {
                vis[curx - 1][cury - 1] = 1;
                q.push(P(curx - 1, cury - 1));
            }
        }//left up

        if (curx - 1 >= 0 && cury + 1 <= m && a[curx][cury + 1] == '.') {
            if (!vis[curx - 1][cury + 1]) {
                vis[curx - 1][cury + 1] = 1;
                q.push(P(curx - 1, cury + 1));
            }
        }//right up

        if (curx + 1 <= n && cury + 1 <= m && a[curx + 1][cury + 1] == '.') {
            if (!vis[curx + 1][cury + 1]) {
                vis[curx + 1][cury + 1] = 1;
                q.push(P(curx + 1, cury + 1));
            }
        }//right down

        if (curx + 1 >= 0 && cury - 1 >= 0 && a[curx + 1][cury] == '.') {
            if (!vis[curx + 1][cury - 1]) {
                vis[curx + 1][cury - 1] = 1;
                q.push(P(curx + 1, cury - 1));
            }
        }//left down

        for (int i = 0; i < 4; i++) {
            int nxtx = curx + movx[i], nxty = cury + movy[i];
            if (nxtx >= 0 && nxty >= 0 && nxtx <= n && nxty <= m && !isWall(nxtx, nxty) && !vis[nxtx][nxty]) {
                vis[nxtx][nxty] = 1;
                q.push(P(nxtx, nxty));
            }
        }
    }
    ans += z;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 0; i <= n; i++) {
        if (!vis[i][0]) bfs(i, 0, 0);
        if (!vis[i][m]) bfs(i, m, 0);
    }
    for (int i = 0; i <= m; i++) {
        if (!vis[0][i]) bfs(0, i, 0);
        if (!vis[n][i]) bfs(n, i, 0);
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (!vis[i][j]) bfs(i, j, 1);
        }
    cout << ans << endl;
    return 0;
}