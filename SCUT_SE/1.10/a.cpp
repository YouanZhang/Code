#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi=acos(-1.0);
const int MAXN = 50000 + 7; 
namespace CG{
    #define Point Vector
    int sgn(double x){
        if (fabs(x)<eps) return 0;
        if (x>0) return 1;
        else return -1;
    }
    struct Point{
        double x,y;
        Point(double x=0,double y=0):x(x),y(y){}
    };
    Point operator + (const Point a,const Point b){return Point(a.x+b.x,a.y+b.y);}
    Point operator - (const Point a,const Point b){return Point(a.x-b.x,a.y-b.y);}
    Vector operator * (const Vector a,const double k){return Vector(a.x*k,a.y*k);}
    Point operator / (const Point a,const double k){return Point(a.x/k,a.y/k);}
    double Dot(const Point a,const Point b){return a.x*b.x+a.y*b.y;}
    double Cross(const Vector a,const Vector b){return a.x*b.y-a.y*b.x;}
    double Norm(const Point a){return sqrt(Dot(a,a));}
    Vector Rotate(const Vector a,const double theta){return Vector(a.x*cos(theta)-a.y*sin(theta),a.x*sin(theta)+a.y*cos(theta));}
    struct Line{
        Point p0,v,p1;
        double t,theta;
        Line(Point _p0=0,Point _v=0,double _t=1):p0(_p0),v(_v),t(_t){p1=p0+v*t; theta=atan2(v.y,v.x);}
        // Line(Point _p0=0,Point _v=0,double _t=1):p0(_p0),p1(_v){v=(p1-p0)/t; theta=atan2(v.y,v.x);}
    };
    Point GetIntersection(const Line n,const Line m){return n.p0+n.v*Cross(m.v,(n.p0-m.p0))/Cross(n.v,m.v);}
    Point GetCircleCenter(const Point a,const Point b,const Point c){
        Point p=(a+b)/2.0,q=(a+c)/2.0;
        Point v=Rotate(b-a,pi/2.0),w=Rotate(c-a,pi/2.0);
        if (sgn(Norm(Cross(v,w)))==0){
            if (sgn(Norm(a-b)+Norm(b-c)-Norm(a-c))==0) return (a+c)/2;
            if (sgn(Norm(b-a)+Norm(a-c)-Norm(b-c))==0) return (b+c)/2;
            if (sgn(Norm(a-c)+Norm(c-b)-Norm(a-b))==0) return (a+c)/2;
        }
        return GetIntersection(Line(p,v),Line(q,w));
    }
    void MinCircleCover(Point p[],int n){
        random_shuffle(p+1,p+1+n);
        Point c=p[1];
        double r=0;
        for (int i=2;i<=n;i++)
            if (sgn(Norm(c-p[i])-r)>0){
                c=p[i],r=0;
                for (int j=1;j<i;j++)
                    if (sgn(Norm(c-p[j])-r)>0){
                        c=(p[i]+p[j])/2.0;
                        r=Norm(c-p[i]);
                        for (int k=1;k<j;k++)
                            if (sgn(Norm(c-p[k])-r)>0){
                                c=GetCircleCenter(p[i],p[j],p[k]);
                                r=Norm(c-p[i]);
                            }
                    }
            }
        printf("%.9f %.9f\n",c.x, r);
    }
}
using namespace CG;
Point P[MAXN * 2];
int main() {
    int n;
    for (scanf("%d", &n); n; scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
            P[i + n].x = P[i].x;
            P[i + n].y = - P[i].y;
        }
        MinCircleCover(P, n * 2);
    }
}