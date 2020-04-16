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
int mn[MAXN], mx[MAXN], mi[MAXN], ma[MAXN], pp[MAXN];
bool p[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    int MAX = 0;
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        mi[i] = INT_INF, ma[i] = -INT_INF;
        for (int j = 1; j <= l; j++) {
            int x;
            cin >> x;
            if (j != 1 && x > mi[i]) p[i] = 1;
            mi[i] = min(mi[i], x);
            ma[i] = max(ma[i], x);
        }
        mn[mi[i]]++; mx[ma[i]]++; pp[ma[i]] += p[i];
        MAX = max(ma[i], MAX);
    }
    for (int i = 1; i <= MAX; i++) mn[i] += mn[i - 1];
    for (int i = 1; i <= MAX; i++) pp[i] += pp[i - 1];
    for (int i = MAX - 1; i >= 0; i--) mx[i] += mx[i + 1];
    for (int i = 1; i <= n; i++) {
        if (p[i]) ans += n;
        else {
            ans += mx[mi[i] + 1];
            ans += pp[mi[i]];
        }
    }
    cout << ans << endl;
    return 0;
}