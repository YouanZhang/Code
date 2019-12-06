#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
queue <int> a[MAXN], ans;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        a[ai].push(i);
    } 
    for (int i = 0, j = 1; j <= n; i++, j++) {
        while (a[i].empty()) {
            i -= 3;
            if (i < 0) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        ans.push(a[i].front()); a[i].pop();
    }
    cout << "Possible" << endl;
    for (; !ans.empty(); ans.pop()) cout << ans.front() << ' ';
    cout << endl;
    return 0;
}