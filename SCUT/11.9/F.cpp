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
const LL INF = 1e15 + 7;
const int MOD = 1e9 + 7;
LL dis[6][6];
LL x, y, z;
LL ch[4];
LL t[4], d;
LL k, i, l, j;
void addEdge(int u, int v, LL w) {
    dis[u][v] = w;
    dis[v][u] = w;
}
void getDis() {
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> x >> y >> z;
    cin >> ch[0] >> ch[1] >> ch[2];
    cin >> t[0] >> t[1] >> t[2] >> d;
    cin >> k >> i >> l >> j;
    k--; l--;
    LL ans = 0;
    getDis();
    if (k == l) {
        if (j < i) swap(i, j);
        if (j <= ch[k] || i >= ch[k] + 1) ans = abs((i - j)) * t[k];
        else {
            ans = (abs((i - ch[k])) + abs((j - (ch[k] + 1)))) * t[k];
            // cerr << dis[0][5] << endl;
            // cerr << dis[0][3] << endl;
            // cerr << dis[3][2] << endl;
            // cerr << dis[2][5] << endl;
            // cerr << t[0] << endl;
            LL D = d;
            if (i != ch[k]) D += d;
            if (j != ch[k] + 1) D += d;
            ans += min(t[k], D + t[(k + 1) % 3] + t[(k + 2) % 3]);
        }
    }
    else {
        int pos1 = 0, pos2 = 0, pos11 = 0, pos22 = 0;
        if (i <= ch[k]) ans += (ch[k] - i) * t[k], pos1 = k;
        else ans += (i - (ch[k] + 1)) * t[k], pos1 = (k + 2) % 3 + 3;
        if (i == ch[k]) addEdge(k, k + 3, 0);
        if (i == ch[k] + 1) addEdge((k + 2) % 3, (k + 2) % 3 + 3, 0);
        if (j <= ch[l]) ans += (ch[l] - j) * t[l], pos2 = l;
        else ans += (j - (ch[l] + 1)) * t[l], pos2 = (l + 2) % 3 + 3;
        if (j == ch[l]) addEdge(l, l + 3, 0);
        if (j == ch[l] + 1) addEdge((l + 2) % 3, (l + 2) % 3 + 3, 0);
        // cerr << ans << endl;
        // cerr << pos1 << pos2 << endl;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++) dis[i][j] = i == j ? 0 : INF;
        addEdge(0, 3, d);
        addEdge(1, 4, d);
        addEdge(2, 5, d);
        addEdge(0, 5, t[0]);
        addEdge(1, 3, t[1]);
        addEdge(2, 4, t[2]);
        // cerr << dis[0][3] << endl;
        // cerr << dis[3][1] << endl;
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        // cout << ans << endl;
        // if (pos1 == pos2) ans += d;
        // else {
        //     if (pos1 == i && pos) 
        // }
        ans += dis[pos1][pos2];
    }
    cout << ans << endl;
    return 0;
}