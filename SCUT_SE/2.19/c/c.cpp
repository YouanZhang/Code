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
P canv[MAXN];
PP cnt[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> canv[i].first >> canv[i].second;
        cnt[i].first = 2;
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        for (int j = 1; j <= n; j++) {
            if (canv[j].first <= x && x <= canv[j].second) {
                if (--cnt[j].first == -1) {
                    cout << "impossible" << endl;
                    return 0;
                } 
                if (cnt[j].first == 1) cnt[j].second.first = x;
                else cnt[j].second.second = x;
            }
        }
    }
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i].first == 0) continue;
        if (canv[i].second == canv[i + 1].first && cnt[i + 1].first != 0 && cnt[i].second.first != canv[i].second && cnt[i].second.second != canv[i].second) {
            ans.push_back(canv[i].second);
            if (--cnt[i].first == 1) cnt[i].second.first = canv[i].second;
            else cnt[i].second.second = canv[i].second;
            if (--cnt[i + 1].first == 1) cnt[i + 1].second.first = canv[i].second;
            else cnt[i + 1].second.second = canv[i].second;
        }
        for (int x = canv[i].first + 1; x < canv[i].second; x++) {
            if (cnt[i].first == 0) break;
            if (x != cnt[i].second.first && x != cnt[i].second.second) {
                ans.push_back(x);
                if (--cnt[i].first == 1) cnt[i].second.first = x;
                else cnt[i].second.second = x;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' '; cout << endl;
    return 0;
}