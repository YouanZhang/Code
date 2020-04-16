#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN];
int n, m;
bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= cnt) cnt++;
        else if (x) x--, cnt++;
        if (cnt >= m) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = n;
    for (; l < r; ) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}