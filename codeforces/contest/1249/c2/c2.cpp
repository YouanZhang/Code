#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 100;
const DB EPS = 1e-9;
LL sumbase[MAXN], base[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        LL n;
        cin >> n;
        LL j = 0; base[0] = sumbase[0] = 1;
        for (LL i = n; i; i /= 3, j++) {
            if (j) base[j] = base[j - 1] * 3, sumbase[j] = base[j] + sumbase[j - 1];
        }
        base[j] = base[j - 1] * 3;
        sumbase[j] = base[j] + sumbase[j - 1];
        LL i, s = 0;
        for (i = j; i >= 0; i--) {
            if (i && s + sumbase[i - 1] < n) s += base[i];
            else if (s + base[i] <= n) s += base[i];
        }
        cout << s << endl;
    }
    return 0;
}