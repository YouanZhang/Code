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
int a[MAXN], b[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    queue <int> m, l;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] > a[i]) m.push(i);
        if (b[i] < a[i]) l.push(i);
    }
    for (; !m.empty(); ) {
        int x = b[m.front()] - a[m.front()];
        int y = a[l.front()] - b[l.front()];
        if (y > x) {
            b[l.front()] += x, b[m.front()] -= x;
            cout << l.front() << ' ' << m.front() << ' ' << x << endl;
            m.pop();
        }
        if (y == x) {
            b[l.front()] += x, b[m.front()] -= y;
            cout << l.front() << ' ' << m.front() << ' ' << x << endl;
            m.pop(), l.pop();
        }
        if (y < x) {
            b[l.front()] += y, b[m.front()] -= y;
            cout << l.front() << ' ' << m.front() << ' ' << y << endl;
            l.pop();
        }
    }
    return 0;
}