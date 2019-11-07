#include <bits/stdc++.h>
using namespace std;
int x[5], y[5];
namespace CG
{
    const double eps=1e-9;
    int sgn(double x){
        if (fabs(x)<eps) return 0;
        if (x>0) return 1;
        else return -1;
    }
    struct Point
    {
        double x, y;
        Point(double x = 0, double y = 0) : x(x), y(y) {}
    };
    typedef Point Vector;
    Vector operator + (const Vector a,const Vector b){return Vector(a.x+b.x,a.y+b.y);}
    Vector operator - (const Vector a,const Vector b){return Vector(a.x-b.x,a.y-b.y);}
    Vector operator * (const Vector a,const double k){return Vector(a.x*k,a.y*k);}
    Vector operator / (const Vector a,const double k){return Vector(a.x/k,a.y/k);}
    double Cross(const Vector a,const Vector b){return a.x*b.y-a.y*b.x;}
    bool ToLeftTest(const Vector a,const Vector b){return Cross(a,b)<0;}
    struct Line
    {
        Point p0, v, p1;
        double t, theta;
        // Line(Point _p0 = 0, Point _v = 0, double _t = 1) : p0(_p0), v(_v), t(_t)
        // {
        //     p1 = p0 + v * t;
        //     theta = atan2(v.y, v.x);
        // }
        // Line(Point _p0=0,Point _v=0,double _t=1):p0(_p0),p1(_v){v=(p1-p0)/t; theta=atan2(v.y,v.x);}
        Line(Point _p0 = 0, Point _p1 = 0) : p0(_p0), p1(_p1)
        {
            v = p1 - p0;
            t = 1;
            theta = atan2(v.y, v.x);
        }
    };
    bool operator < (const Line n,const Line m) {return n.theta<m.theta;}
    Point GetIntersection(const Line n,const Line m){return n.p0+n.v*Cross(m.v,(n.p0-m.p0))/Cross(n.v,m.v);}
    void HalfPlaneIntersection(Line l[], int n)
    {
        deque<Point> p;
        sort(l + 1, l + 1 + n);
        deque<Line> q;
        q.push_back(l[1]);
        for (int i = 2; i <= n; i++)
        {
            for (; !p.empty() && !ToLeftTest(p.back() - l[i].p0, l[i].v); q.pop_back(), p.pop_back())
                ;
            for (; !p.empty() && !ToLeftTest(p.front() - l[i].p0, l[i].v); q.pop_front(), p.pop_front())
                ;
            if (sgn(Cross(l[i].v, q.back().v)) == 0)
                if (ToLeftTest(l[i].p0 - q.back().p0, q.back().v))
                {
                    q.pop_back();
                    if (!p.empty())
                        p.pop_back();
                }
            if (!q.empty())
                p.push_back(GetIntersection(q.back(), l[i]));
            q.push_back(l[i]);
        }
        for (; !p.empty() && !ToLeftTest(p.back() - q.front().p0, q.front().v); q.pop_back(), p.pop_back())
            ;
        p.push_back(GetIntersection(q.back(), q.front()));
        if (p.size() < 3) printf("0\n");
        else
        {
            cerr << "!" << endl;
            double area = 0.5 * Cross(p.back(), p.front());
            Point last = p.front();
            for (p.pop_front(); !p.empty(); last = p.front(), p.pop_front())
                area += 0.5 * Cross(last, p.front());
            printf("%.8lf\n", fabs(area));
        }
    }
} // namespace CG
// using namespace CG;
CG::Line l[8];
int main()
{
    while (cin >> x[1] >> y[1])
    {
        for (int i = 2; i <= 4; i++) cin >> x[i] >> y[i];

        if ((x[2] - x[1]) * (y[2] - y[1]) < 0){
            l[1] = CG::Line(CG::Point (x[1], y[1]), CG::Point(x[1], y[2]));
            l[2] = CG::Line(CG::Point (x[1], y[2]), CG::Point(x[2], y[1]));
            l[3] = CG::Line(CG::Point (x[2], y[1]), CG::Point(x[1], y[1]));
        }
        else{
            l[1] = CG::Line(CG::Point (x[1], y[1]), CG::Point(x[2], y[1]));
            l[2] = CG::Line(CG::Point (x[2], y[1]), CG::Point(x[1], y[2]));
            l[3] = CG::Line(CG::Point (x[1], y[2]), CG::Point(x[1], y[1]));
        }
        l[4] = CG::Line(CG::Point (x[3], y[3]), CG::Point(x[4], y[3]));
        l[5] = CG::Line(CG::Point (x[4], y[3]), CG::Point(x[4], y[4]));
        l[6] = CG::Line(CG::Point (x[4], y[4]), CG::Point(x[3], y[4]));
        l[7] = CG::Line(CG::Point (x[3], y[4]), CG::Point(x[3], y[3]));
        CG::HalfPlaneIntersection(l, 7);
    }
}
