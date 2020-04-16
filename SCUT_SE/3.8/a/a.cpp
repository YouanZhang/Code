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
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    if (n == 2) {
        swap(s[0], s[1]), swap(t[0], t[1]);
        if (s > t) cout << "YES" << endl << 1 << ' ' << 2 << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (s[0] > t[0]) cout << "YES" << endl << 2 << ' ' << 3 << endl;
    else {
        for (int i = 1; i < n; i++)
            if (s[i] > t[i]) {
                cout << "YES" << endl << 1 << ' ' << i + 1 << endl;
                return 0;
            }
        cout << "NO" << endl;
    }
    return 0;
}