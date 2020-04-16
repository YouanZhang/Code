#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e3+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
#define Point Vector
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}S[MAXN], R[MAXN], M[MAXN];
Vector operator + (const Vector a,const Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (const Vector a,const Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (const Vector a,const double k){return Vector(a.x*k,a.y*k);}
double Cross(const Vector a,const Vector b){return a.x*b.y-a.y*b.x;}
bool PointInConvexHull(Point A, Point *p, int tot){
    int l=1,r=tot-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        double a1=Cross(p[mid]-p[0],A-p[0]);
        double a2=Cross(p[mid+1]-p[0],A-p[0]);
        if(a1>=0 && a2<=0){
            if(Cross(p[mid+1]-p[mid],A-p[mid])>=0) return true;
            return false;
        }
        else if(a1<0) r=mid-1;
        else l=mid+1;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int s, r, m; cin >> s >> r >> m;
    for (int i = 0; i < s; i++) cin >> S[i].x >> S[i].y;
    for (int i = 0; i < r; i++) cin >> R[i].x >> R[i].y;
    for (int i = 0; i < m; i++) cin >> M[i].x >> M[i].y;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        Point t; cin >> t.x >> t.y;
        if (PointInConvexHull(t, S, s)) cout << "Sheena" << endl;
        else if (PointInConvexHull(t, R, r)) cout << "Rose" << endl;
        else if (PointInConvexHull(t, M, m)) cout << "Maria" << endl;
        else cout << "Outside" << endl;
    }
    return 0;
}