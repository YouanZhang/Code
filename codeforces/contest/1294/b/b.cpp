#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e3+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
P a[MAXN];
bool cmp(P a, P b) {return a.first == b.first ? a.second < b.second : a.first < b.first;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        sort(a + 1, a + 1 + n, cmp);
        bool flag = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i].second < a[i - 1].second) flag = 0;
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            while (x != a[i].first) {
                cout << 'R';
                x++;
            }
            while (y != a[i].second) {
                cout << 'U';
                y++;
            }
        }
        cout << endl;
    }
    return 0;
}