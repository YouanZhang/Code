#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <P, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
string nam[20];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> nam[i];
    string s; cin >> s;
    PP w = PP (P(1, 1), P(3, 3)), b = PP (P(2, 2), P(4, 4));
    queue <int> q;
    for (int i = 5; i <= n; i++) q.push(i);
    int con = 0, max_con = 0;
    vector <PP> ans;
    for (int i = 0; i < s.size(); i++) {
        swap(w.first, w.second);
        swap(b.first, b.second);
        if (s[i] == 'W') {
            q.push(b.first.first); b.first = P (q.front(), i + 5); q.pop();
            if (i && s[i - 1] == 'W') con++;
            else con = 1;
            if (con > max_con) {
                ans.clear();
                ans.push_back(w);
                max_con = con;
            }
            else if (con == max_con) ans.push_back(w);
        }
        else {
            q.push(w.first.first); w.first = P(q.front(), i + 5); q.pop();
            if (i && s[i - 1] == 'B') con++;
            else con = 1;
            if (con > max_con) {
                ans.clear();
                ans.push_back(b);
                max_con = con;
            }
            else if (con == max_con) ans.push_back(b);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].first.second > ans[i].second.second) swap(ans[i].first, ans[i].second);
        cout << nam[ans[i].first.first] << ' ' << nam[ans[i].second.first] << endl;
    }
    return 0;
}