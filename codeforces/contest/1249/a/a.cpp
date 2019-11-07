#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 0;
const DB EPS = 1e-9;
int a[107];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        bool flag = 0;
        for (int i = 2; i <= n; i++) 
            if (a[i] == a[i - 1] + 1) flag = 1;
        cout << flag + 1 << endl;
    }
    return 0;
}