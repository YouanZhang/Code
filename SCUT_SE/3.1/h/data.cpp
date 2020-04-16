#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char mp[N][N];
int main() {
    srand(time(0));
    int n = rand() % N, m = rand() % N, d = rand() % 10;
    cout << n << ' ' << m << ' ' << d << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            mp[i][j] = '.';
    }
    int p = rand() % N;
    for (int i = 1; i <= p; i++)
        mp[rand() % n][rand() % m] = 'M';
    mp[rand() % n][rand() % m] = 'S';
    mp[rand() % n][rand() % m] = 'F';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << mp[i][j];
        cout << endl;
    }
}