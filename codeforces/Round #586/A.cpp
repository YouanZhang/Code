#include <bits/stdc++.h>
using namespace std;
int cnt[300];
int main(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cnt[s[i]]++;
    }
    for (int i = 1; i <= cnt['n']; i++){
        if (cnt['o'] && cnt['e']){
            --cnt['o']; --cnt['e'];
            cout << 1 << ' ';
        }
        else break;
    }
    for (int i = 1; i <= min(cnt['z'], cnt['r']); i++){
        if (cnt['o'] && cnt['e']){
            --cnt['o']; --cnt['e'];
            cout << 0 << ' ';
        }
        else break;
    }
    cout << endl;
}