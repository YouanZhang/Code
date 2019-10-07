#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;
int a[MAXN], t[MAXN << 2];
void build(int u, int l, int r) {
    if (l == r) {
        t[u] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    t[u] = min(t[u << 1], t[u << 1 | 1]);
}
int query(int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[u];
    int mid = (l + r) >> 1;
    int ret = INF;
    if (x <= mid) ret = query(u << 1, l, mid, x, y);
    if (mid + 1 <= y) ret = min(query(u << 1 | 1, mid + 1, r, x, y), ret);
    return ret;
}
int main() {
    int n, q;
    while (cin >> n >> q) {
        string s;
        cin >> s;
        for (int i = 0; i <= n * 4; i++) t[i] = INF;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') a[i + 1] = 1;
            else a[i + 1] = -1;
            a[i + 1] += a[i];
        }
        build(1, 1, n);
        for (int i = 1; i <= q; i++) {
            int u, v;
            cin >> u >> v;
            if (s[u - 1] == s[v - 1]) cout << "Yes" << endl;
            else{
                if (u > v) swap(u, v);
                if (s[u - 1] == ')') cout << "Yes" << endl;
                else {
                    if (query(1, 1, n, u, v - 1) < 2) cout << "No" << endl;
                    else cout << "Yes" << endl;
                }
            }
        }
    }
}