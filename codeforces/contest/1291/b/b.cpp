#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 3e5+7;
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
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = n - 1;
        for (int i = 0; i < n; i++) {
            if (a[i] < i) {
                l = i - 1;
                break;
            }
        }
        int r = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < n - i - 1) {
                r = i + 1;
                break;
            }
        }
        if (l >= r) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}