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
    int ca;
    for (cin >> ca; ca; ca--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        queue <int> l, r;
        for (int i = 0; i < (n - (2 * k - 2)) / 2; i++)
            if (s[i] != '(') r.push(i);
        for (int i = (n - (2 * k - 2)) / 2; i < n - (2 * k - 2); i++)
            if (s[i] != ')') l.push(i);
        for (int i = n - (2 * k - 2); i < n; i += 2)
            if (s[i] != '(') r.push(i);
        for (int i = n - (2 * k - 2) + 1; i < n; i += 2)
            if (s[i] != ')') l.push(i);
        vector <P> ans;
        for (; !r.empty(); ) {
            ans.push_back(P(min(r.front(), l.front()), max(r.front(), l.front())));
            if (ans.back().first + 1 != ans.back().second) ans.push_back(P(min(r.front(), l.front()) + 1, max(r.front(), l.front()) - 1));
            r.pop(); l.pop();
        }
        cout << ans.size() << endl;
        for (auto u : ans) {
            cout << u.first + 1 << ' ' << u.second + 1 << endl;
        }
    }
    return 0;
}