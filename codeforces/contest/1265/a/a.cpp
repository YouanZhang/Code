#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    int t = 'a' + 'b' + 'c';
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            if (s[0] == '?') cout << 'a' << endl;
            continue;
        }
        int tag = -1, flag = 0;
        for (int j = 0; j < s.length(); j++) {
            if (j > 0 && s[j] == s[j - 1] && s[j] != '?') flag = 1;
        }
        if (flag == 1) {
            cout << -1 << endl;
            continue;
        }
        for (int j = 0; j < s.length(); j++) {
            if (s[j] != '?') continue;
            if (j - 1 >= 0) s[j] = s[j - 1] + 1;
            else s[j] = 'a';
            if (s[j] == 'd') s[j] = 'a';
            if (j + 1 < s.length() && s[j] == s[j + 1]) s[j]++;
            if (s[j] == 'd') s[j] = 'a';
        }
        cout << s << endl;
    }
    return 0;
}