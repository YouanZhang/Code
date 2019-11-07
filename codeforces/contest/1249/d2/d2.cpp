#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5 + 7;
const DB EPS = 1e-9;
int a[MAXN];
vector <P> L[MAXN];
vector <int> ans;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++; a[r + 1]--;
        L[l].push_back(P(r, i));
    }
    for (int i = 1; i <= 200000; i++) {
        a[i] += a[i - 1];
        if (a[i] >= k) {
            sort(L[i].begin(), L[i].end(), greater <>() );
            for (int j = 0; j < a[i] - k; j++) {
                a[L[i][j].first + 1]++;
                ans.push_back(L[i][j].second);
            }
            a[i] = k;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << ' ';
    cout << endl;
    return 0;
}