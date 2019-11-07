#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
// typedef pair <int, int> P;
// typedef pair <int, P> PP;
const int MAXN = 0;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
struct Point{
    DB x, y;
};
bool cmpxy(Point a, Point b) {
    return fabs(a.x - b.x) < EPS ? a.y < b.y : a.x < b.x;
}
bool cmpy(Point a, Point b) {
    return a.y < b.y;
}
DB DisPP(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
vector <Point> P;
DB CP(int l, int r) {
    if (l == r) return DB_INF;
    if (l + 1 == r) return DisPP(P[l], P[r]);
    int mid = (l + r) >> 1;
    DB d = min(CP(l, mid), CP(mid + 1, r));
    vector <Point> tmp;
    for (int i = l; i <= r; i++)
        if (fabs(P[mid].x - P[i].x) < d) tmp.push_back(P[i]);
    sort(tmp.begin(), tmp.end(), cmpy);
    for (int i = 0; i < tmp.size(); i++)
        for (int j = i + 1; j < tmp.size() && tmp[j].y - tmp[i].y < d; j++)
            d = min(d, DisPP(tmp[i], tmp[j]));
    return d;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(2); cout << fixed;
    for (int n; cin >> n && n; ) {
        P.clear();
        for (int i = 1; i <= n; i++) {
            DB _x, _y;
            cin >> _x >> _y;
            P.push_back(Point{_x, _y});
        }
        sort(P.begin(), P.end(), cmpxy);
        cout << CP(0, n - 1) / 2 << endl;
    }
    return 0;
}