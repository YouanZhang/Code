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
int a[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n, x;
        cin >> n >> x;
        for ( int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        a[++n] = INT_INF;
        int i = 1, j = 0;
        while (1) {
            if (a[i] <= j + 1) j = a[i], i++;
            else {
                if (--x < 0) break;
                j++;
            }
        }
        cout << j << endl;
    } 
    return 0;
}