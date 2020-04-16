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
    double x, y;
    double theta;
    bool flag;
    LL g;
};
typedef Point Vector;
double ang(Point a, Point b) {
    return atan2(b.y - a.y, b.x - a.x);
}
Point p[MAXN], pm[MAXN];
int n; 
inline int nxt(int x) {return (x + 1) % n;}
inline bool cmp_theta(Point a, Point b) {return a.theta < b.theta;}
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
        pm[i] = p[i];
        pm[nxt(i)] = p[nxt(i)]; pm[nxt(i)].theta = ang(pm[i], pm[nxt(i)]); pm[nxt(i)].flag = 0;
        while (pm[nxt(i)].theta < 0) pm[nxt(i)].theta += 2 * pi;
        for (int j = nxt(nxt(i)); j != i; j = nxt(j)) {
            pm[j] = p[j];
            pm[j].theta = ang(pm[i], pm[j]);
            pm[j].theta = pm[j].theta - pm[nxt(i)].theta;
            while (pm[j].theta < 0) pm[j].theta += 2 * pi;
            if (pm[j].theta > pi) pm[j].flag = 1, pm[j].theta -= pi, neg += pm[j].g,;
            else pos += pm[j].g;
        }
        pm[nxt(i)].theta = 0;
        ans = min(ans, abs(neg - pos));
        sort(pm, pm + n, cmp_theta);
        for (int j = 2; j < n; j++) {
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