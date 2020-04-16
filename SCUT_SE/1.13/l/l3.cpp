#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int N=2005;
const double eps=1e-8;

inline int sgn(double x){
    if(abs(x)<eps) return 0;
    else return x<0?-1:1;
}

struct Vector{
    double x,y;
    Vector(double a=0,double b=0):x(a),y(b){}
    bool operator <(const Vector &a)const{
        return sgn(x-a.x)<0||(sgn(x-a.x)==0&&sgn(y-a.y)<0);
    }
};
typedef Vector Point;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator *(Vector a,double b){return Vector(a.x*b,a.y*b);}
Vector operator /(Vector a,double b){return Vector(a.x/b,a.y/b);}
bool operator ==(Vector a,Vector b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}

double Len(Vector a){return sqrt(Dot(a,a));}
double Len2(Vector a){return Dot(a,a);}
double DisTL(Point p,Point a,Point b){
    Vector v1=p-a,v2=b-a;
    return abs(Cross(v1,v2)/Len(v2));
}
int ConvexHull(Point p[],int n,Point ch[]){
    sort(p+1,p+1+n);
    int m=0;
    for(int i=1;i<=n;i++){
        while(m>1&&sgn(Cross(ch[m]-ch[m-1],p[i]-ch[m-1]))<=0) m--;
        ch[++m]=p[i];
    }
    int k=m;
    for(int i=n-1;i>=1;i--){
        while(m>k&&sgn(Cross(ch[m]-ch[m-1],p[i]-ch[m-1]))<=0) m--;
        ch[++m]=p[i];
    }
    if(n>1) m--;
    cerr << m << endl;
    return m;
}
double S(Vector a,Vector b){return abs(Cross(a,b));}
double RotatingCalipers(Point p[],int n){
    if(n<3) return 0;
    if(n==4) return abs(Cross(p[3]-p[1],p[2]-p[1]))/2+abs(Cross(p[3]-p[1],p[4]-p[1]))/2;
    double ans=0;
    p[n+1]=p[1];
    for(int i=1;i<=n-2;i++){
        int k=i+1,l=(i+2)%n+1;
        for(int j=i+2;j<=n;j++){
            while(k+1<j&&sgn(S(p[k]-p[i],p[j]-p[i])-S(p[k+1]-p[i],p[j]-p[i]))<0) k=k+1;
            while(l%n+1!=i&&sgn(S(p[l]-p[i],p[j]-p[i])-S(p[l%n+1]-p[i],p[j]-p[i]))<0) l=l%n+1;
            ans=max(ans,S(p[k]-p[i],p[j]-p[i])/2+S(p[l]-p[i],p[j]-p[i])/2);
        }
    }
    return ans;
}

int n;
Point p[N],ch[N];
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    n=ConvexHull(p,n,ch);
    double ans=RotatingCalipers(ch,n);
        if ((long long)(ans * 10) % 10 == 0)
            cout << (long long)ans << endl;
        else
            cout << ans << endl;
}