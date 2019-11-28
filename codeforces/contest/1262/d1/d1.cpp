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
    vector <P> a;
    for (int i = 1; i <= n; i++) {
        int elem;
        cin >> elem;
        a.push_back(P(-elem, i));
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int k, pos;
        cin >> k >> pos;
        vector <P> ans;
        for (int j = 0; j < k; j++) ans.push_back(P(a[j].second, -a[j].first));
        sort(ans.begin(), ans.end());
        cout << ans[pos - 1].second << endl;
    }
    return 0;
}