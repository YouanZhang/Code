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
    string s, t; cin >> s; t = s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            if (i >= 2 && t[i - 1] == 'B' && t[i - 2] == 'B') t[i] = 'P';
            else t[i] = 'B';
        }
        else {
            if (i >= 2 && t[i - 1] == 'D' && t[i - 2] == 'D') t[i] = 'T';
            else t[i] = 'D';
        }
    }
    cout << t << endl;
    return 0;
}