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
int a[300], b[300];
string s, t;
int find(char x) {
    for (int i = 0; i < t.size(); i++) if (t[i] == x) return i;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int T;
    for (cin >> T; T; T--) {
        int n;
        cin >> n;
        cin >> s >> t;
        memset(a, 0, sizeof (a));
        memset(b, 0, sizeof (b));
        for (int i = 0; i < n; i++) {
            a[s[i]]++;
            b[t[i]]++;
        }
        bool flag = 0;
        for (int i = 'a'; i <= 'z'; i++) if ((a[i] + b[i]) & 1) flag = 1;
        if (flag) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        queue <char> la;
        for (int i = 'a'; i <= 'z'; i++) {
            //for (int j = 0; j <= a[i] - (a[i] + b[i]) / 2; j++) ma.push_back(i);
            for (int j = 0; j <= (a[i] + b[i]) / 2 - a[i]; j++) la.push(i);
        }
        vector <P> ans;
        for (int i = 0; i < n; i++) {
            if (a[s[i]] > (a[s[i]] + b[s[i]]) / 2) {
                int j = find(la.front());
                a[s[i]]--; b[s[i]]++;
                a[t[j]]++; b[t[j]]--;
                swap(s[i], t[j]);
                la.pop();
                ans.push_back(P(i, j));
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                int J = 0;
                for (int j = i + 1; j < n; j++) {
                    if (t[j] == s[i]) {
                        if (!J) J = j;
                        else if (t[i] == s[j]) J = j;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (s[j] == t[i]) {
                        ans.push_back(P(j, J));
                        ans.push_back(P(j, i));
                        break;
                    }
                }
                swap(t[i], t[J]);
            }
        }
        if (ans.size() > 2 * n) cout << "No" << endl;
        else {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
        }
    }
    return 0;
}