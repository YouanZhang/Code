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
int h[107];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            h[x]++;
        }
    int i = 100;
    for (; v; i--) {
        v -= h[i];
        h[i - 1] += h[i];
    }
    cout << i << endl;
    return 0;
}