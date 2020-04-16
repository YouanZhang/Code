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
int cnt[MAXN], a[MAXN][MAXN], dep[i];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        for (int j = 1; j <= cnt[i]; j++) {
            int x; cin >> x;
            a[i][x] = 1;
        }
        if (cnt[i] == 0) q.push(i), dep[i] = 1;
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= n; i++) {
            if (a[i][cur]) {
                cnt[i]--;
                if (cnt[i] == 0) q.push(i), dep[i] = dep[cur] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dep[i] == dep[j] + 1) cout << 
        }
    }
    return 0;
}