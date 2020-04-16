#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <pair <DB, int> , P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
PP a[MAXN];
queue <int> q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second.first >> a[i].second.second;
        a[i].first.first = 1.0 * a[i].second.second / a[i].second.first;
        a[i].first.second = i;
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        cerr << a[i].first.first << ' ' << a[i].first.second << endl;
        if (v >= a[i].second.first) v -= a[i].second.first, ans += a[i].second.second, q.push(a[i].first.second);
    }
    cout << ans << endl;
    for (; !q.empty(); q.pop()) cout << q.front() << ' ';
    cout << endl;
    return 0;
}