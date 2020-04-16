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
string s[MAXN];
int p[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(2); cout << fixed;
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        cin >> p[i];
        sum += p[i];
    }
    vector <P> ans;
    for (int i = 1; i <= n; i++) {
        int Q = (sum - p[i]) * 100;
        int l = -1, r = 100001;
        for (int P = max(0, p[i] * 100 - 50); P <= min(10000, p[i] * 100 + 49); P++) 
            if (10000 - P >= Q - (n - 1) * 50 && 10000 - P <= Q + (n - 1) * 49) {
                l = P;
                break;
            }
        for (int P = min(10000, p[i] * 100 + 49); P >= max(0, p[i] * 100 - 50); P--)  
            if (10000 - P >= Q - (n - 1) * 50 && 10000 - P <= Q + (n - 1) * 49) {
                r = P;
                break;
            }
        if (l == -1 ) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans.push_back(P(l, r));
    }
    for (int i = 0; i < n; i++) {
        cout << s[i + 1] << ' ' << ans[i].first * 1.0 / 100 << ' ' << ans[i].second * 1.0 / 100 << endl;
    }
    return 0;
}