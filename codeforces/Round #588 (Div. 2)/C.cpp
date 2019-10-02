#include <bits/stdc++.h>
using namespace std;
int d[10], u[100], v[100], t[10][10];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
        t[u[i]][v[i]] = t[v[i]][u[i]] = 1;
        d[u[i]]++; d[v[i]]++;
    }
    int ans = 0;
    if (n == 7){
        int mn = 10, mi = 10, ans = 0;
        for (int i = 1; i <= n; i++){
            if (d[i] < mn) mn = d[i], mi = i;
        }
        for (int i = 1; i <= 7; i++){
            if (i == mi) continue;
            int s = 0;
            for (int j = 1; j <= 7; j++){
                if (t[mi][j] && !t[i][j]) s++;
            }
            ans = max(ans, s);
        }
        cout << m - mn + ans << endl;
    }
    else{
        cout << m << endl;
    }
}