#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <LL, LL> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
vector <P> a;
int len;
LL l = 1, r = 1;
P ans;
void dfs(int dep) {
    if (dep == len) {
        if (max(l, r) < max(ans.first, ans.second)) ans = P(l, r);
        return;
    }
    for (int i = 1; i <= a[dep].second; i++) l *= a[dep].first;
    dfs(dep + 1);
    for (int i = 1; i <= a[dep].second; i++) l /= a[dep].first;
    for (int i = 1; i <= a[dep].second; i++) r *= a[dep].first;
    dfs(dep + 1);
    for (int i = 1; i <= a[dep].second; i++) r /= a[dep].first;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n;
    cin >> n;
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    ans = P(1, n);
    LL x = n;
    for (LL i = 2; i <= sqrt(n) + 1; i++) {
        int cnt = 0;
        for (; x % i == 0; x /= i) cnt++;
        if (cnt) a.push_back(P(i, cnt));
    }
    if (x != 1) a.push_back(P(x, 1));
    len = a.size();
    dfs(0);
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}