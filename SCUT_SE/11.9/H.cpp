#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> P;
const int MAXN = 107;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, m;
    string s, t[MAXN];
    cin >> n;
    cin >> s;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> t[i];
    vector <P> ans;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int cori = 0, corj = 0, inci = 0, incj = 0, cor = 0, inc = 0;
            for (int k = 0; k < n; k++) {
                if (t[i][k] == s[k]) cori++;
                else inci++;
                if (t[j][k] == s[k]) corj++;
                else incj++;
                if (t[i][k] == t[j][k]) {
                    if (t[i][k] == s[k]) cor++;
                    else inc++;
                }
            }
            if (cor * 2 > cori && cor * 2 > corj && inc * 2 > inci && inc * 2 > incj) ans.push_back(P(i, j));
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}