#include <bits/stdc++.h>
using namespace std;
int a[307][307];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i & 1) a[i][j] = i * n + j + 1;
            else a[i][j] = i * n + n - j;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}