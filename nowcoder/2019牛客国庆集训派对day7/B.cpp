#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    LL a, b, c;
    while (cin >> a >> b >> c){
        LL p = (a + b + a + c) * b * c;
        LL q = (a + b) * (a + c) * (a + b + c);
        cout << p / __gcd(p, q) << "/" << q / __gcd(p, q) << ' ';

        swap(a, b);
        p = (a + b + a + c) * b * c;
        q = (a + b) * (a + c) * (a + b + c);
        cout << p / __gcd(p, q) << "/" << q / __gcd(p, q) << ' ';

        swap(a, c);
        p = (a + b + a + c) * b * c;
        q = (a + b) * (a + c) * (a + b + c);
        cout << p / __gcd(p, q) << "/" << q / __gcd(p, q) << endl;
    }
}