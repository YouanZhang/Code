#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> P;
int x[20], y[20], n;
int dis[20][20];
int dist[1 << 16 | 7][20];
bool in[1 << 16 | 7][20];
queue <P> q;
int getDis(int x, int y){
    if (x == 0 && y == 0) return 0;
    if (x == 1 && y == 1) return 6;
    if (x > y) swap(x, y);
    if (x == 0 || x == 1) return x + y + 2 * (y % 4 != 0);
    return x + y;
}
int main(){
    int Ca;
    for (scanf("%d", &Ca); Ca; --Ca){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            scanf("%d %d", &x[i], &y[i]);
            for (int j = 0; j < i; ++j){
                dis[i][j] = dis[j][i] = getDis(abs(x[i] - x[j]), abs(y[i] - y[j]));
            }
        }
        for (int i = 0; i < (1 << n); ++i)
            for (int j = 0; j < n; ++j) dist[i][j] = 1 << 30, in[i][j] = 0;
        for (int i = 0; i < n; ++i)
            q.push(P(1 << i, i)), dist[1 << i][i] = getDis(abs(x[i]), abs(y[i])), in[1 << i][i] = 1;
        for (P cur = q.front(); !q.empty(); q.pop(), in[cur.first][cur.second] = 0, cur = q.front()){
            for (int i = 0; i < n; ++i){
                if ((1 << i) & cur.first) continue;
                P nxt = P(cur.first | (1 << i), i);
                if (dist[cur.first][cur.second] + dis[cur.second][i] < dist[nxt.first][nxt.second]){
                    dist[nxt.first][nxt.second] = dist[cur.first][cur.second] + dis[cur.second][i];
                    if (in[nxt.first][nxt.second]) continue;
                    q.push(nxt);
                    in[nxt.first][nxt.second] = 1;
                }
            }
        }
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i) ans = min(ans, dist[(1 << n) - 1][i]);
        printf("%d\n", ans);
    }
}