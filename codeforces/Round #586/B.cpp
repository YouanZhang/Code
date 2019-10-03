#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 7;
long long a[MAXN], M[MAXN][MAXN];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> M[i][j];
    a[3] = sqrt(M[2][3] * M[1][3] / M[1][2]);
    a[1] = M[1][3] / a[3];
    a[2] = M[1][2] / a[1];
    for (int i = 4; i <= n; i++)
        a[i] = M[1][i] / a[1];
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
}