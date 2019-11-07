#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e4+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
vector <int> p;
string s, t;
bool check() {
    if (p.empty()) return true;
    if (p.size() != 2) return false;
    int i = p[0], j = p[1];
    if (s[i] == s[j] && t[i] == t[j]) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int T;
    for (cin >> T; T; T--) {
        int n;
        cin >> n;
        cin >> s >> t;
        p.clear();
        for (int i = 0; i < n; i++) if (s[i] != t[i]) p.push_back(i);
        if (check()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}