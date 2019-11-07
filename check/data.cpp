#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    int n = rand() * rand() % 100000 + 1;
    cout << n << endl;
    for (int j = 1; j <= n ; j++) cout << rand()%1000 << ' ' << rand()%1000 << endl;
}