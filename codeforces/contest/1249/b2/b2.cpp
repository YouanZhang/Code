#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5 + 7;
const DB EPS = 1e-9;
int a[MAXN], p[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (!p[i]) {
                int s = 1;
                for (int j = a[i]; j != i; j = a[j]) s++;
                p[i] = s;
                for (int j = a[i]; j != i; j = a[j]) p[j] = s;
            }
        }
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << endl;
    }
    return 0;
}