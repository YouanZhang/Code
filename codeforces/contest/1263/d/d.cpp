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
int last[30], fa[MAXN];
int getFa(int x) {return (x == fa[x] ? x : fa[x] = getFa(fa[x]));}
void connect(int u, int v) {
    int fu = getFa(u), fv = getFa(v);
    if (fu == fv) return;
    fa[fu] = fv;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (last[s[j] - 'a']) {
                connect(i, last[s[j] - 'a']);
            }
            // cerr << last[s[j] - 'a'] << endl;
            last[s[j] - 'a'] = i;
            // for (int i = 1; i <= n; i++) {
            //     cerr << fa[i] << ' ';
            // }
            // cerr << endl;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += fa[i] == i;
        // cerr << fa[i] << ' ';
    }
    cout << ans << endl;
    return 0;
}