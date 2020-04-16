#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e7 + 7;
const int MOD = 1e9 + 7;
int n, m, d;
int mp[MAXN];
char MP[MAXN];
void mark(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) mp[x * m + y] = -1;
}
queue <P> q; 
void move(int x, int y, int step) {
    if (x >= 0 && x < n && y >= 0 && y < m && mp[x * m + y] == 0) mp[x * m + y] = step + 1, q.push(P(x, y));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> m >> d;
    P s, f;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> MP[i * m + j];
            if (MP[i * m + j] == 'S') s = P(i, j);
            if (MP[i * m + j] == 'F') f = P(i, j);
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch = MP[i * m + j];
            if (ch == 'M') {
                if (abs(s.first - i) + abs(s.second - j) <= d) {
                    cout << -1 << endl;
                    return 0;
                }
                for (int x = 0; x <= d; x++) {
                    int y = d - x;
                    mark(i + x, j + y);
                    mark(i - x, j + y);
                    mark(i + x, j - y);
                    mark(i - x, j - y);
                }
            }
        }
    }
    q.push(s); mp[s.first * m + s.second] = 1;
    while (!q.empty()) {
        P cur = q.front(); q.pop();
        move(cur.first + 1, cur.second, mp[cur.first * m + cur.second]);
        move(cur.first - 1, cur.second, mp[cur.first * m + cur.second]);
        move(cur.first, cur.second + 1, mp[cur.first * m + cur.second]);
        move(cur.first, cur.second - 1, mp[cur.first * m + cur.second]);
    }
    if (mp[f.first * m + f.second] > 0) cout << mp[f.first * m + f.second] - 1 << endl;
    else cout << -1 << endl;
    return 0;
}