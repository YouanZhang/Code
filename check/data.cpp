#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    for (int i = 1; i <= 30; i++) {
        int n = rand() * rand() % 100000 + 1;
        cout << n << endl;
        for (int j = 1; j <= n ; j++) cout << rand()%10;
        cout << endl;
    }
}