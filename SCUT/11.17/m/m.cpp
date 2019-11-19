#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2007;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN];
unordered_map <int, int> mp;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int t;
    for (cin >> t; t; t--) {
        int n; cin >> n;
        LL ans = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (mp[a[i]]) ans += mp[a[i]];
            if (i == n) break;
            for (int j = 1; j < i; j++) mp[2 * a[i] - a[j]]++;
        }
        cout << ans << endl;
    }
    return 0;
}