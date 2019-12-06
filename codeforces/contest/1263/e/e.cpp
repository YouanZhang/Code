#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e6+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
struct Sgt {
    int l, r, sum, mn, mx, tag;
}t[MAXN << 2];
void build(int node, int l, int r) {
    t[node].l = l; t[node].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 ^ 1, mid + 1, r);
}
void pushdown(int node){
    if (t[node].tag == 0) return;
    t[node].sum += t[node].tag;
    t[node].mx += t[node].tag;
    t[node].mn += t[node].tag;
    if (t[node].l != t[node].r) {
        t[node << 1].tag += t[node].tag;
        t[node << 1 ^ 1].tag += t[node].tag;
    }
    else {
        t[node].mn = t[node].mx = t[node].sum;
    }
    t[node].tag = 0;
}
void pushup(int node) {
    if (t[node].l == t[node].r) t[node].mn = t[node].mx = t[node].sum;
    else {
        t[node].mn = min(t[node << 1].mn, t[node << 1 ^ 1].mn);
        t[node].mx = max(t[node << 1].mx, t[node << 1 ^ 1].mx);
    }
}
void add(int node, int l, int r, int c) {
    if (l <= t[node].l && t[node].r <= r) {
        t[node].tag += c;
        pushdown(node);
        return;
    }
    pushdown(node);
    if (t[node].l == t[node].r) return;
    int mid = (t[node].l + t[node].r) >> 1;
    if (l <= mid) add(node << 1, l, r, c);
    if (mid + 1 <= r) add(node << 1 ^ 1, l, r, c);
    pushup(node);
}
int getSum(int node, int l, int r) {
    if (l == 0) return 0;
    pushdown(node);
    if (l <= t[node].l && t[node].r <= r) return t[node].sum;
    int mid = (t[node].l + t[node].r) >> 1;
    int s = 0;
    if (l <= mid) s += getSum(node << 1, l, r);
    if (mid + 1 <= r) s += getSum(node << 1 ^ 1, l, r);
    pushup(node);
    return s;
}
int getMin(int node, int l, int r) {
    pushdown(node);
    if (l <= t[node].l && t[node].r <= r) {
        pushup(node);
        return t[node].mn;
    }
    int mid = (t[node].l + t[node].r) >> 1;
    int s1 = INT_INF, s2 = INT_INF;
    pushdown(node);
    if (l <= mid) s1 = min(s1, getMin(node << 1, l, r));
    if (mid + 1 <= r) s2 = min(s2, getMin(node << 1 ^ 1, l, r));
    return min(s1, s2);
    pushup(node);
}
int getMax(int node, int l, int r) {
    pushdown(node);
    if (l <= t[node].l && t[node].r <= r) {
        pushup(node);
        return t[node].mx;
    }
    int mid = (t[node].l + t[node].r) >> 1;
    int s1 = -INT_INF, s2 = -INT_INF;
    pushdown(node);
    if (l <= mid) s1 = max(s1, getMax(node << 1, l, r));
    if (mid + 1 <= r) s2 = max(s2, getMax(node << 1 ^ 1, l, r));
    return max(s1, s2);
    pushup(node);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    string s;
    cin >> n;
    cin >> s;
    build(1, 1, n);
    for (int i = 0, cur = 1; i < n; i++) {
        if (s[i] == '(') add(1, cur, n, 1 - getSum(1, cur, cur) + getSum(1, cur - 1, cur - 1));
        if (s[i] == ')') add(1, cur, n, -1 - getSum(1, cur, cur) + getSum(1, cur - 1, cur - 1));
        if (s[i] >= 'a' && s[i] <= 'z') add(1, cur, n, 0 - getSum(1, cur, cur) + getSum(1, cur - 1, cur - 1));
        if (s[i] == 'L') cur = max(1, cur - 1);
        if (s[i] == 'R') cur++;
        if (getSum(1, n, n) == 0 && getMin(1, 1, n) == 0) cout << getMax(1, 1, n) << ' ';
        else cout << -1 << ' ';
    }
    cout << endl;
    return 0;
}