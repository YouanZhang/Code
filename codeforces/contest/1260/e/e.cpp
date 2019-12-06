#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int MAXN = (1 << 18) + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
LL a[MAXN];
struct P {
    LL first, second;
    bool operator < (const P &b) const {
        return (first == b.first ? second < b.second : first > b.first);
    }
    P (LL _f, LL _s) : first(_f), second(_s) {}
};
priority_queue <LL, vector <LL>, greater <LL> > q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL n;
    cin >> n;
    LL tag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            tag = i;
        }
    }
    LL ans = 0;
    for (int i = n, cnt = n >> 1; i > tag; i -= cnt, cnt >>= 1) {
        if (q.empty()) {
            ans += a[i];
        }
        else {
            if (q.top() <= a[i]) {
                ans += q.top();
                q.pop();
                q.push(a[i]);
            }
            else ans += a[i];

        }
        for (int j = 1; j < cnt; j++) q.push(a[i - j]);
    }
    cout << ans << endl;
    return 0;
}