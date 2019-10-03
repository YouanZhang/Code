#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    char mn = s[0];
    for (int i = 0; i < n; i++){
        if (s[i] > mn){
            cout << "Ann" << endl;
        }
        else{
            cout << "Mike" << endl;
            mn = min(s[i], mn);
        }
    }
}