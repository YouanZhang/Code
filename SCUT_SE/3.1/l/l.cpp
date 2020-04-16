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
int app[300], nxt[MAXN][300];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    string s;
    cin >> s;
    for (int i = 'a'; i <= 'z'; i++) {
        app[i] = s.size();
        nxt[s.size()][i] = s.size();
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 'a'; j <= 'z'; j++) nxt[i][j] = app[j];
        app[s[i]] = i;
    }
    int n;
    stack <int> st;
    for (cin >> n; n; n--) {
        string pf; cin >> pf;
        if (pf.size() == 4) {
            char ch; cin >> ch;
            if (st.empty()) st.push(app[ch]);
            else st.push(nxt[st.top()][ch]);
        }
        else if (!st.empty()) st.pop();
        if (st.empty() || st.top() != s.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}