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
struct Point
{
    double x, y;
    Point(double x=0,double y=0):x(x),y(y){}
} a[MAXN], st, q[MAXN];
typedef Point Vector;
bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
Vector operator - (const Vector a,const Vector b){return Vector(a.x-b.x,a.y-b.y);}
double Cross(const Vector a,const Vector b){return a.x*b.y-a.y*b.x;}
double DisPP(const Vector a,const Vector b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double cross(Point a, Point b, Point c)
{
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
bool comp(Point a, Point b)
{
    if (cross(a, b, st) > 0)
        return 1;
    if (cross(a, b, st) == 0 && fabs(a.x - st.x) < fabs(b.x - st.x))
        return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(1);
    cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--)
    {
        double ans = 0;
        int n, top, t1, t2;
        cin >> n;
        st.x = st.y = INT_INF;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
            q[i].x = q[i].y = 0;
            if (a[i].y < st.y || a[i].y == st.y && a[i].x < st.x)
                st = a[i];
        }
        sort(a + 1, a + n + 1, comp);
        q[1] = a[1];
        q[2] = a[2];
        top = 2;
        for (int i = 3; i <= n; i++)
        {
            while (top > 1 && cross(q[top - 1], a[i], q[top]) >= 0)
                top--;
            q[++top] = a[i];
        }
        if (top < 3) {
            cout << 0 << endl;
            continue;
        }
        if (top == 3)
        {
            ans = abs(cross(q[1], q[2], q[3])) / 2;
            double mn = DB_INF;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == q[1] || a[i] == q[2] || a[i] == q[3])
                    continue;
                double mi = abs(cross(a[i], q[2], q[3])) / 2;
                mi = min(mi, abs(cross(q[1], a[i], q[3])) / 2);
                mi = min(mi, abs(cross(q[1], q[2], a[i])) / 2);
                mn = min(mn, mi);
            }
            ans -= mn;
        }
        else
        {
            double dis = 0;
            for (int i = 1, j = 3; i <= top; ++i)
            {
                while (abs(Cross(q[i + 1] - q[i], q[j] - q[i])) < abs(Cross(q[i + 1] - q[i], q[j + 1] - q[i])))
                    j = j % top + 1;
                if (DisPP(q[j], q[i]) >= DisPP(q[j], q[i + 1])) {
                    t2 = i;
                    t1 = j;
                    while (cross(q[t1 + 1], q[i], q[j]) >= cross(q[t1], q[i], q[j]))
                        t1 = t1 % top + 1;
                    while (cross(q[i], q[t2 + 1], q[j]) >= cross(q[i], q[t2], q[j]))
                        t2 = t2 % top + 1;
                    ans = max(ans, (cross(q[t1], q[i], q[j]) + cross(q[i], q[t2], q[j])) / 2);
                }
                if (DisPP(q[j], q[i]) <= DisPP(q[j], q[i + 1])) {
                    t2 = i + 1;
                    t1 = j;
                    while (cross(q[t1 + 1], q[i], q[j]) >= cross(q[t1], q[i], q[j]))
                        t1 = t1 % top + 1;
                    while (cross(q[i], q[t2 + 1], q[j]) >= cross(q[i], q[t2], q[j]))
                        t2 = t2 % top + 1;
                    ans = max(ans, (cross(q[t1], q[i], q[j]) + cross(q[i], q[t2], q[j])) / 2);
                }
            }
            // for (int i = 1; i <= top; i++)
            // {
            //     t2 = i % top + 1;
            //     t1 = (i + 2) % top + 1;
                
            // }
        }
        if ( (LL)(ans * 10) % 10 == 0) cout << (LL) ans << endl;
        else cout << ans << endl;
    }
    return 0;
}