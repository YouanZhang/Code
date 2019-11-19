#include <bits/stdc++.h>
using namespace std;
long long a[3];
int main() {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    long long ans = 0;
    ans += a[1] - a[0];
    a[2] += a[1] - a[0];
    a[0] += a[1] - a[0];
    ans += a[2] - a[0];
    cout << ans << endl;
}