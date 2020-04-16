#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, P> PP;
const int MAXN = (1 << 12) + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
struct Point{
    LL x, y;
    Point(LL _x, LL _y): x(_x), y(_y){}
}p[MAXN];
typedef pair <Point, Point> P;
LL dis(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    for (int ca; ca; ca--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
        queue <P> mxPP;
        mxPP.push(P(Point(0, 0), Point(0, 0)));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (dis(p[i], p[j]) > dis(mxPP.front().first, mxPP.front().second)) {
                    while (!mxPP.empty()) mxPP.pop();
                    mxPP.push(P(p[i], p[j]));
                }
                else if (dis(p[i], p[j]) == dis(mxPP.front().first, mxPP.front().second)) mxPP.push(P(p[i], p[j]));
            }
        }
        while (!mxPP.empty()) {
            P cur = mxPP.front(); mxPP.pop();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j) continue;
                    
                }
            }
        }
    }
    return 0;
}