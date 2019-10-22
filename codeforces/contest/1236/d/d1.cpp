#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int R[MAXN], L[MAXN], U[MAXN], D[MAXN];
int r, l, u, d;
vector <int> X[MAXN], Y[MAXN];
bool moveR() {
    for (auto i : X[u]) 
        if (i >= l && i <= r) {
            if (R[i] - R[r + 1] < (d - u + 1) * (r - i + 1)) return false;
            r = i - 1; u++;
            return true;
        }
    u++;
    return true;
}
bool moveD() {
    for (auto i : Y[r]) 
        if (i >= u && i <= d) {
            if (D[i] - D[d + 1] < (r - l + 1) * (d - i + 1)) return false;
            d = i - 1; r--;
            return true;
        }
    r--;
    return true;
}
bool moveL() {
    for (auto it = X[d].rbegin(); it != X[d].rend(); it++) {
        int i = *it;
        if (i >= l && i <= r) {
            if (L[i] - L[l - 1] < (d - u + 1) * (i - l + 1)) return false;
            l = i + 1; d--;
            return true;
        }
    }
    d--;
    return true;
}
bool moveU() {
    for (auto it = Y[l].rbegin(); it != Y[l].rend(); it++) {
        int i = *it;
        if (i >= u && i <= d) {
            if (U[i] - U[u - 1] < (r - l + 1) * (i - u + 1)) return false;
            u = i + 1; l++;
            return true;
        }
    }
    l++;
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= K; i++) {
        int _x, _y;
        cin >> _x >> _y;
        X[_x].push_back(_y);
        Y[_y].push_back(_x);
        R[_y]++; L[_y]++; U[_x]++; D[_x]++;
    }
    for (int i = 1; i <= m; i++) L[i] += L[i - 1];
    for (int i = m; i >= 1; i--) R[i] += R[i + 1];
    for (int i = 1; i <= n; i++) U[i] += U[i - 1];
    for (int i = n; i >= 1; i--) D[i] += D[i + 1];
    for (int i = 1; i <= n; i++) sort(X[i].begin(), X[i].end());
    for (int i = 1; i <= m; i++) sort(Y[i].begin(), Y[i].end());
    bool ans = 0;
    for (l = 1, r = m, u = 1, d = n; ;) {
        if (!moveR()) break;
        if (l > r || u > d) {
            ans = 1;
            break;
        }
        if (!moveD()) break;
        if (l > r || u > d) {
            ans = 1;
            break;
        }
        if (!moveL()) break;
        if (l > r || u > d) {
            ans = 1;
            break;
        }
        if (!moveU()) break;
        if (l > r || u > d) {
            ans = 1;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}