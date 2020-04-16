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
int a[MAXN], cnt[MAXN];
int n, m;
void mark(int l, int r) {
    cnt[l]++; cnt[r + 1]--;
    if (l > r) cnt[0]++;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            if (abs(x) == n) cnt[0]++;
            if (x >= 0) mark(a[i], (a[i] + x) % n);
            else mark((a[i] + x + n) % n, a[i]);
        }
        for (int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }
        P ans = P(0, 0);
        for (int i = 0; i < n; i++) 
            if (cnt[i] > ans.second) ans = P(i + 1, cnt[i]);
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}