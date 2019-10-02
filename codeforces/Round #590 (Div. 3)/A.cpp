#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int n, sum;
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << (sum + n - 1) / n << endl;
    }

}