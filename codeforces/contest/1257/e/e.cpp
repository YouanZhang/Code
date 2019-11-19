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
int bel[MAXN], K[4];
set <int> st[4];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    for (int k = 1; k <= 3; k++) cin >> K[k];
    int n = K[1] + K[2] + K[3];
    for (int k = 1; k <= 3; k++) 
        for (int i = 1; i <= K[k]; i++) {
            int x;
            cin >> x;
            bel[x] = k;
            st[k].insert(x);
        }
    int ans = 0;
    for (int k = 1, h = 1, t = n; !st[1].empty() && !st[3].empty();) {
        if (st[1].empty()) k = 3;
        else if (st[3].empty()) k = 1;
        else if (*st[1].begin() - h < t - *st[3].rbegin()) k = 1;
        else if (*st[1].begin() - h > t - *st[3].rbegin()) k = 3;
        if (k == 1) {
            for (; !st[1].empty() && *st[1].begin() == h; st[1].erase(h++));
            if (st[1].empty()) continue;
            int be = *st[1].begin();
            int delta = 0;
            for (int i = h; i < be; i++) delta += (bel[i] == 3);
            if (be - h - delta < st[1].size()) {
                ans += be - h;
                for (; h < be; h++) {
                    st[bel[h]].erase(h);
                }
            }
            else {
                ans += st[1].size();
                st[1].clear();
            }
        }
        else {
            for (; !st[3].empty() && *st[3].rbegin() == t; st[3].erase(t--));
            if (st[3].empty()) continue;
            int rbe = *st[3].begin();
            int delta = 0;
            for (int i = rbe + 1; i <= t; i++) delta += (bel[i] == 1);
            if (t - rbe - delta < st[3].size()) {
                ans += t - rbe;
                for (; t > rbe; t--) {
                    st[bel[t]].erase(t);
                }
            }
            else {
                ans += st[3].size();
                st[3].clear();
            }
        }
    }
    cout << ans << endl;
    return 0;
}