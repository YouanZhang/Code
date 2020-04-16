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
P a[10], b[10];
int n, ans = 0;
vector <int> l;
//  int cntt[362888];
bool in[10];
bool check() {
    int cnta = 0, cntb = 0;
    if (l.size() <= 1) return false;
    for (int i = 0; i < int(l.size()) - 1; i++) {
        int u = l[i], v = l[i + 1];
        if (u > v) swap(u, v);
        for (int i = 1; i <= n; i++) 
            if (u == a[i].first && v == a[i].second) {
                cnta++;
                break;
            }
        for (int i = 1; i <= 8; i++) 
            if (u == b[i].first && v == b[i].second) {
                cntb++;
                break;
            }
    }
    if (cnta == n && cntb == 0) {
        // //  for (int i = 0; i < l.size(); i++) cerr << l[i]; cerr << endl;
        return true;
    }
    return false;
}
//  int cnt = 0;
void dfs(int dep, int tot) {
    if (dep == tot + 1) {
        ans += check();
        // cnt++;
        return;
    }
    for (int i = 1; i <= 9; i++)
        if (!in[i]) {
            in[i] = 1;
            l.push_back(i);
            dfs(dep + 1, tot);
            l.pop_back();
            in[i] = 0;
        }
}
void doit(int dep, int tot) {
    if (dep == 10) {
        //  cnt = 0;
        dfs(1, 9 - tot);
        //  cerr << cnt << endl;
        //   cntt[cnt]++;
        return;
    }
    in[dep] = 1;
    doit(dep + 1, tot + 1);
    in[dep] = 0;
    doit(dep + 1, tot);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    b[1] = P(1, 3);
    b[2] = P(4, 6);
    b[3] = P(7, 9);
    b[4] = P(1, 7);
    b[5] = P(2, 8);
    b[6] = P(3, 9);
    b[7] = P(1, 9);
    b[8] = P(3, 7);
    doit(1, 0);
    cout << ans << endl;
    return 0;
}