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
int a[MAXN], cnt[MAXN], in[MAXN], ans[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    stack <int> s;
    s.push(a[1]); cnt[a[1]]--;
    in[a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        cnt[a[i]]--;
        if (in[a[i]]) continue;
        for (; !s.empty() && a[i] < s.top() && cnt[s.top()]; ) {
            in[s.top()] = 0;
            s.pop();
        }
        s.push(a[i]);
        in[a[i]] = 1;
    }
    for (int i = k; i >= 1; i--) 
        ans[i] = s.top(), s.pop();
    for (int i = 1; i <= k; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}