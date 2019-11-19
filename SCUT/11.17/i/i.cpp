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
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    int minx = INT_INF, miny = INT_INF, maxx = -INT_INF, maxy = -INT_INF;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        minx = min(minx, x - z);
        maxx = max(maxx, x + z);
        miny = min(miny, y - z);
        maxy = max(maxy, y + z);
    }
    int deltax = maxx - minx;
    if (deltax & 1) deltax++;
    int deltay = maxy - miny;
    if (deltay & 1) deltay++;
    int Z = max(deltax, deltay) / 2;
    int X = minx + deltax / 2;
    int Y = miny + deltay / 2;
    cout << X << ' ' << Y << ' ' << Z << endl;
    return 0;
}