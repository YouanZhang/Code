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
P il[MAXN];
int tag[6][3000];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> il[i].first >> il[i].second;
        il[i].second += 1500;
    }
    il[0] = P(0, 1500);
    il[++n] = P(l, 1500);
    sort(il, il + 1 + n);
    int ri = 1;
    for (; ri <= n && il[ri].first <= 5; ri++) tag[il[ri].first][il[ri].second] = -1;
    tag[0][1500] = 1; 
    int le = 0;
    for (int i = 0; i < l; i++) {
        for (; ri <= n && il[ri].first - i == 5; ri++) tag[il[ri].first % 6][il[ri].second] = -1;
        for (; le <= n && il[le].first == i; le++) {
            if (tag[il[le].first % 6][il[le].second] <= 0) continue;
            for (int x = 1; x <= 5; x++) {
                for (int y = -(5 - x); y <= 5 - x; y++) {
                    if (tag[(il[le].first + x) % 6][il[le].second + y] != 0)
                        tag[(il[le].first + x) % 6][il[le].second + y] = max(tag[(il[le].first + x) % 6][il[le].second + y], tag[il[le].first % 6][il[le].second] + 1);
                }
            }
        }
        memset(tag[i % 6], 0, sizeof(tag[i % 6]));
    }
    cout << tag[l % 6][1500] - 2 << endl;
    return 0;
}