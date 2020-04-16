#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int MAXN = (1 << 12) + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI = acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
namespace CG
{
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
typedef Point Vector;
Vector operator+(const Vector a, const Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator-(const Vector a, const Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator*(const Vector a, const double k) { return Vector(a.x * k, a.y * k); }
Vector operator/(const Vector a, const double k) { return Vector(a.x / k, a.y / k); }
bool operator<(const Vector a, const Vector b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool operator==(const Vector a, const Vector b) { return a.x == b.x && a.y == b.y; }
double Dot(const Vector a, const Vector b) { return a.x * b.x + a.y * b.y; }
double Cross(const Vector a, const Vector b) { return a.x * b.y - a.y * b.x; }
double mult_Cross(const Vector a, const Vector b, const Vector c) { return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y); }
double mult_Dot(const Vector a, const Vector b, const Vector c) { return (a.x - c.x) * (b.x - c.x) + (a.y - c.y) * (b.y - c.y); }
double DisPP(const Vector a, const Vector b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
} // namespace CG
namespace CG
{
bool cmp(Point a, Point b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int ConvexHull(Point *p,int n,Point *s){
        sort(p,p+n,cmp); //x从小到大,y从小到大;
        int m=-1;
        for (int i=0;i<n;i++){
            for (;m>=1 && Cross(s[m]-s[m-1],p[i]-s[m])<=0;m--);
            s[++m]=p[i];
        }
        int k=m;
        for (int i=n-2;i;i--){
            for (;m>=k+1 && Cross(s[m]-s[m-1],p[i]-s[m])<=0;m--);
            s[++m]=p[i];
        }
        return m + 1;
    }
} // namespace CG
namespace CG
{
double RotatingCalipers(Point *q, int n)
{
    // double dis=0;
    double ans = 0;
    for (int i = 0, j = 2; i < n; ++i)
    {
        while (abs(Cross(q[i + 1] - q[i], q[j] - q[i])) < abs(Cross(q[i + 1] - q[i], q[j + 1] - q[i])))
            j = (j + 1) % n;
        if (DisPP(q[j], q[i]) >= DisPP(q[j], q[i + 1]) && abs(i - j) > 1)
        {
            int t2 = i;
            int t1 = j;
            // cerr << "t1 = " << t1 << endl;
            // cerr << "t2 = " << t2 << endl;
            while (abs(mult_Cross(q[t1 + 1], q[i], q[j])) >= abs(mult_Cross(q[t1], q[i], q[j]))) t1 = (t1 + 1) % n;
            while (abs(mult_Cross(q[t2 + 1], q[i], q[j])) >= abs(mult_Cross(q[t2], q[i], q[j]))) t2 = (t2 + 1) % n;
            // cerr << "t1 = " << t1 << endl;
            // cerr << "t2 = " << t2 << endl;
            ans = max(ans, (abs(mult_Cross(q[t1], q[i], q[j])) + abs(mult_Cross(q[t2], q[i], q[j]))) / 2);
            // cerr << "ans = " << abs(mult_Cross(q[t1], q[i], q[j])) << '+' << abs(mult_Cross(q[t2], q[i], q[j])) << '=' << ans << endl;
            if (ans == 4) cerr << i << ' ' << j << ' ' << t1 << ' ' << t2 << endl;
        }
        if (DisPP(q[j], q[i]) <= DisPP(q[j], q[(i + 1) % n]) && abs((i + 1) % n - j) > 1)
        {
            int t2 = (i + 1) % n;
            int t1 = j;
            while (abs(mult_Cross(q[t1 + 1], q[(i + 1) % n], q[j])) >= abs(mult_Cross(q[t1], q[(i + 1) % n], q[j]))) 
                t1 = (t1 + 1) % n;
            while (abs(mult_Cross(q[t2 + 1], q[(i + 1) % n], q[j])) >= abs(mult_Cross(q[t2], q[(i + 1) % n], q[j])))
                t2 = (t2 + 1) % n;
            ans = max(ans, (abs(mult_Cross(q[t1], q[(i + 1) % n], q[j])) + abs(mult_Cross(q[t2], q[(i + 1) % n], q[j]))) / 2);
            // if (ans == 4) cerr << (i + 1) % n << ' ' << j << ' ' << t1 << ' ' << t2 << endl;
        }
        // dis=max(dis,max(DisPP(p[j],p[i]),DisPP(p[j],p[i+1])));
    }
    return ans;
    // return dis;
}
} // namespace CG
CG ::Point p[MAXN], q[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(1);
    cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
            q[i].x = q[i].y = 0;
        }
        int m = CG ::ConvexHull(p, n, q);
        if (m < 3)
        {
            cout << 0 << endl;
            continue;
        }
        double ans = 0;
        if (m == 3)
        {
            ans = abs(CG::mult_Cross(q[1], q[2], q[3])) / 2;
            double mn = DB_INF;
            for (int i = 0; i < n; i++)
            {
                if (p[i] == q[0] || p[i] == q[1] || p[i] == q[2])
                    continue;
                double mi = abs(CG::mult_Cross(p[i], q[1], q[2])) / 2;
                mi = min(mi, abs(CG::mult_Cross(q[0], p[i], q[2])) / 2);
                mi = min(mi, abs(CG::mult_Cross(q[0], q[1], p[i])) / 2);
                mn = min(mn, mi);
            }
            if (mn != DB_INF) ans -= mn;
        }
        else
        {
            ans = CG::RotatingCalipers(q, m);
        }
        if ((LL)(ans * 10) % 10 == 0)
            cout << (LL)ans << endl;
        else
            cout << ans << endl;
    }
    return 0;
}