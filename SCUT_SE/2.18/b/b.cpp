#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <string, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    map <string, int> mp;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    P ans;
    for (auto i = mp.begin(); i != mp.end(); i++) {
        if (i->second > ans.second) ans.second = i->second, ans.first = i->first;
    }
    if (ans.second * 2 > n) cout << ans.first << endl;
    else cout << "NONE" << endl;
    return 0;
}