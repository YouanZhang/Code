#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    int n = rand() % 10 + 1, m = rand() % 600 + 1;
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) cout << rand() % 60 + 1 << ' '; cout << endl;
    for (int i = 1; i <= n; i++) cout << rand() % 60 + 1 << ' '; cout << endl;
}