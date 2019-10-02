#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, x;
    char c;
    cin >> n >> k;
    cin >> c;
    x = c - '0';
    if (k >= n){
        cout << 0 << endl;
        return 0;
    }
    if (x != 1 && k){
        x = 1;
        k--;
    }
    cout << x;
    for (int i = 2; i <= n ; i++){
        cin >> c;
        x = c - '0';
        if (x && k){
            x = 0;
            k--;
        }
        cout << x;
    }
    cout << endl;
}