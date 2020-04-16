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
int a[MAXN], cnt[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ansmin = 0;
    for (int i = 1; i <= n; ) {
        if (cnt[i] != 0) i += 3, ansmin++;
        else i++;
    }
    cout << ansmin << ' ';


    sort(a + 1, a + 1 + n);
    vector <P> q;
    int last = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] - a[i - 1] > 1) q.push_back(P(last, i - 1)), last = i;
    q.push_back(P(last, n));
    int ansmax = 0;
    for (int i = 0; i < q.size(); i++) {
        int l = q[i].first, r = q[i].second;
        ansmax += a[r] - a[l] + 1;
        if ((r - l) - (a[r] - a[l]) >= 1) {
            if (cnt[a[l] - 1] == 0) ansmax++, cnt[a[l] - 1] = 1;
            else ansmax++, cnt[a[r] + 1] = 1;
        }
        if ((r - l) - (a[r] - a[l]) >= 2)
            if (cnt[a[r] + 1] == 0) ansmax++, cnt[a[r] + 1] = 1;
    }
    cout << ansmax << endl;
    return 0;
}