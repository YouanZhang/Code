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
PP a[MAXN];
int f[MAXN], nxt[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, w, h; cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second.first;
        a[i].second.second = i;
    }
    sort(a + 1, a + 1 + n);
    int st = n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i].first > w) {
            st = i;
            break;
        }
    }
    int ans = 0, last;
    for (int i = st; i <= n; i++) {
        if (a[i].second.first <= h) continue;
        f[i] = 1;
        for (int j = st; a[i].first > a[j].first; j++) 
            if (a[i].second.first > a[j].second.first) {
                if (f[j] + 1 > f[i]) f[i] = f[j] + 1, nxt[i] = j;
            }
        if (f[i] > ans) ans = f[i], last = i;
    }
    if (ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    stack <int> g;
    for (int i = last; ; i = nxt[i]) {
        g.push(a[i].second.second);
        if (nxt[i] == 0) break;
    }
    cout << g.size() << endl;
    while (!g.empty()) {
        cout << g.top() << ' ';
        g.pop();
    }
    cout << endl;
    return 0;
}