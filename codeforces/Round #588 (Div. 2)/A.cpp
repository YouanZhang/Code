#include <bits/stdc++.h>
using namespace std;
int main(){
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int s = a1 + a2 + a3 + a4;
    if (s % 2 == 0){
        if (a1 + a2 == s / 2 || a1 + a3 == s / 2 || a1 + a4 == s / 2 || a2 + a3 == s / 2 || a2 + a4 == s / 2 || a3 + a4 == s / 2 || a1 == s /2 || a2 == s / 2 || a3 == s /2 || a4 == s /2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
}