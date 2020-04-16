#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 5e4+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
map <string, int> mp, han;
string handle[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> handle[i];
        han[handle[i]] = 0;
    }
    for (int i = 1; i <= m; i++) {
        string id;
        int sco;
        cin >> id >> sco;
        mp[id] = sco;
    }
    for (int i = 1; i <= q; i++) {
        string user, pro, ver;
        cin >> user >> pro >> ver;
        if (ver[0] == 'W') continue;
        if (han.find(user) != han.end()) han[user] += mp[pro];
    }
    for (int i = 1; i <= n; i++) cout << handle[i] << ' ' << han[handle[i]] << endl;
    return 0;
}