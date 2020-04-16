#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n, k;
P a[10];
double A;
double ans, suc;
bool p[10];
void solve_suc(int dep) {
    if (dep == n + 1) {
        double pro = 1;
        double B = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i]) pro *= 1.0 * a[i].second / 100, cnt++;
            else pro *= 1.0 - 1.0 * a[i].second / 100, B += a[i].first;
        }
        if (cnt * 2 <= n) pro = pro * A / (A + B);
        suc += pro;
        return;
    }
    p[dep] = 1;
    solve_suc(dep + 1);
    p[dep] = 0;
    solve_suc(dep + 1); 
}
void dfs(int dep) {
    if (dep == n + 1) {
        suc = 0;
        solve_suc(1);
        ans = max(ans, suc);
        return;
    }
    for (int i = 0; i <= k; i++) {
        int delta = min(i * 10, 100 - a[dep].second);
        a[dep].second += delta; k -= i;
        dfs(dep + 1);
        a[dep].second -= delta; k += i;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(10); cout << fixed;
    cin >> n >> k >> A;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    dfs(1);
    cout << ans << endl;
    return 0; 
}