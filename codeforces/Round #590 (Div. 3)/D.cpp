#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
string s;
int n;
int t[26][MAXN];
int lowbit(int x) {
    return x&(-x);
}
void add(int c, int i, int x) {
    while(i <= n){
        t[c][i] += x;
        i += lowbit(i);
    }
}
int sum(int c, int i)
{
    int s = 0;
    while(i > 0) {
        s += t[c][i];
        i -= lowbit(i);
    }
    return s;
}
int main() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) 
        add(s[i] - 'a', i + 1, 1);
    int q;
    cin >> q; 
    for (int i = 1; i <= q; i++){
        int typ;
        cin >> typ;
        if (typ == 1){
            int pos;
            char cha;
            cin >> pos >> cha;
            add(s[pos - 1] - 'a', pos, -1);
            add(cha - 'a', pos, 1);
            s[pos - 1] = cha;
        }
        else{
            int l, r;
            cin >> l >> r;
            int s = 0;
            for (int i = 0; i < 26; i++) 
                s += (bool) (sum(i, r) - sum(i, l - 1));
            cout << s << endl;
        }
    }
}