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
    int n; cin >> n;
    vector <P> a;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back(P(l, r));
    }
    sort(a.begin(), a.end());
    P cur = a[0];
    queue <int> ans;
    for (int i = 1; i < n; i++) {
        if (a[i].first > cur.second) {
            ans.push(cur.first);
            cur = a[i];
        }
        else cur.first = max(cur.first, a[i].first), cur.second = min(cur.second, a[i].second);
    }
    ans.push(cur.first);
    cout << ans.size() << endl;
    for (; !ans.empty(); ans.pop()) cout << ans.front() << ' ';
    cout << endl;
    return 0;
}