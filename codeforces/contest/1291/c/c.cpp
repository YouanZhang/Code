#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 3500+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n, m, k; cin >> n >> m >> k;
        if (k >= m) k = m - 1;
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector <int> b;
        for (int l = 1, r = n - m + 1; r <= n; l++, r++) {
            b.push_back(max(a[l], a[r]));
        }
        map <int, int> c;
        for (int i = 0; i < m - k; i++) c[b[i]]++;
        int ans = c.begin()->first;
        for (int l = 1, r = m - k; r < b.size(); l++, r++) {
            if (--c[b[l - 1]] == 0) c.erase(b[l - 1]);
            c[b[l]]++;
            if (--c[b[r - 1]] == 0) c.erase(b[r - 1]);
            c[b[r]]++;
            ans = max(ans, c.begin()->first);
        }
        cout << ans << endl;
    }
    return 0;
}