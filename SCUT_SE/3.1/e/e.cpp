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
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << "NO" << endl;
        return 0;
    }
    int l = 0, r = s.size() - 1;
    for (; s[l] == t[l] && l < s.size(); l++);
    for (; s[r] == t[r] && r >= 0; r--);
    if (l >= r) cout << "YES" << endl;
    else {
        bool flag = 1;
        for (int i = l, j = r; i <= r; i++, j--) 
            if (s[i] != t[j]) flag = 0;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}