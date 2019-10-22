#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int main() {
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << (g[i][j] ? '@' : '.');
        cout << endl;
    }
}