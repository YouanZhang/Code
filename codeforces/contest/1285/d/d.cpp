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
vector <LL> a[2];
LL x[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n; cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    a[0].push_back(x[1]);
    for (LL i = 2; i <= n; i++) 
        if (x[i] != x[i - 1]) a[0].push_back(x[i]);
    LL cur = 0;
    if (a[0].size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    int len = 0;
    for (int x = a[0][a[0].size() - 1]; x; x >>= 1) len++;
    for (LL b = 0; b < len; b++, cur ^= 1) {
        a[cur ^ 1].clear();
        // for (int i = 0; i < a[cur].size(); i++) cerr << a[cur][i] << ' '; cerr << endl;
        for (LL i = 0; i < a[cur].size(); i++) {
            if (i == a[cur].size() - 1) 
                a[cur ^ 1].push_back(a[cur][i] - (a[cur][i] & (1 << b)));
            else {
                LL ai = a[cur][i] | ((1 << (b + 1)) - 1);
                LL aj = a[cur][i + 1] | ((1 << (b + 1)) - 1);
                if (ai == aj) {
                    LL ak;
                    // cerr << (a[cur][i] & ((1 << (b)) - 1)) << endl;
                    // cerr << (a[cur][i + 1] & ((1 << (b)) - 1)) << endl;
                    if ((a[cur][i] & ((1 << (b)) - 1)) < (a[cur][i + 1] & ((1 << (b)) - 1))) ak = a[cur][i];
                    else ak = a[cur][i + 1];
                    ak |= (1 << b);
                    a[cur ^ 1].push_back(ak);
                    i++;
                }
                else {
                    a[cur ^ 1].push_back(a[cur][i] - (a[cur][i] & (1 << b)));
                }
            }
        }
    }
    cout << a[cur][0] << endl;
    return 0;
}