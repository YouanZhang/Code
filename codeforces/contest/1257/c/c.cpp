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
int last[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca; 
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) last[i] = -INT_INF;
        int ans = INT_INF;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            ans = min(ans, i - last[x] + 1);
            last[x] = i;
        }
        cout << (ans > n ? -1 : ans) << endl;
    }
    return 0;
}