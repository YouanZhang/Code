#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
set <int> x[MAXN], y[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    long long n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= K; i++) {
        int _x, _y;
        cin >> _x >> _y;
        x[_x].insert(_y);
        y[_y].insert(_x);
    }
    long long ans = 0;
    for (int l = 1, r = m, u = 1, d = n; l <= r && u <= d; ) {
        if (l > r || u > d) break;
        if (!x[u].empty()) {
            if (x[u].find(l) != x[u].end()) break;
            if (x[u].lower_bound(l) != x[u].end()) r = min(r, *x[u].lower_bound(l) - 1);
        }
        ans += r - l + 1; 
        u++;
        if (l > r || u > d) break;
        if (!y[r].empty()) {
            if (y[r].find(u) != y[r].end()) break;
            if (y[r].lower_bound(u) != y[r].end()) d = min(d, *y[r].lower_bound(u) - 1);
        }
        ans += d - u + 1;
        r--;
        if (l > r || u > d) break;
        if (!x[d].empty()) {
            if (x[d].find(r) != x[d].end()) break;
            if (x[d].lower_bound(r) != x[d].begin()) l = max(l, *(--x[d].lower_bound(r)) + 1);
        }
        ans += r - l + 1;
        d--;
        if (l > r || u > d) break;
        if (!y[l].empty()) {
            if (y[l].find(d) != y[l].end()) break;
            if (y[l].lower_bound(d) != y[l].begin()) u = max(u, *(--y[l].lower_bound(d)) + 1);
        }
        ans += d - u + 1;
        l++;
    }
    cout << (ans + K == n * m ? "Yes" : "No") << endl;
    return 0;
}