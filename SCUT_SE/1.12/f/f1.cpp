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
const double pi=acos(-1.0);
struct Point {
    LL x, y;
    bool flag;
    LL g;
};
Point p[MAXN], pm[MAXN];
int n; 
inline int nxt(int x) {return (x + 1) % n;}
inline bool cmp(Point a, Point b) {
    return a.x * b.y > a.y * b.x;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> p[i].x >> p[i].y >> p[i].g;
    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }
    LL ans = 1LL * 1000000000 * 4000 + 7;
    for (int i = 0; i < n; i++) {
        LL pos = 0, neg = 0;
        Point O = p[i];
        for (int j = nxt(i), cnt = 0; j != i; j = nxt(j), cnt++) {
            Point cur = p[j];
            cur.x -= O.x;
            cur.y -= O.y;
            if (cur.y < 0) cur.x = -cur.x, cur.y = -cur.y, cur.flag = 1, neg += cur.g;
            else pos += cur.g;
            pm[cnt] = cur;
        }
        sort(pm, pm + n - 1, cmp);
        if (pm[0].flag == 0) pos -= pm[0].g;
        else neg -= pm[0].g;
        ans = min(ans, abs(neg - pos));
        for (int j = 1; j < n - 1; j++) {
            if (pm[j].flag == 0) pos -= pm[j].g;
            else neg -= pm[j].g;
            if (pm[j - 1].flag == 0) neg += pm[j - 1].g;
            else pos += pm[j - 1].g;
            ans = min(ans, abs(neg - pos));
        }
    }
    cout << ans << endl;
    return 0;
}