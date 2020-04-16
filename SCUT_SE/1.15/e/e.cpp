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
const int MOD = 11092019;
int cnt[300];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
    LL ans = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        ans = ans * (cnt[i] + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}