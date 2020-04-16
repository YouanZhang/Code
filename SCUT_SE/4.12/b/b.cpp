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
int n;
    #define Point Vector
    struct Point{
        int x,y;
        Point(int x=0,int y=0):x(x),y(y){}
    };
    Vector operator + (const Vector a,const Vector b){return Vector(a.x+b.x,a.y+b.y);}
    Vector operator - (const Vector a,const Vector b){return Vector(a.x-b.x,a.y-b.y);}
    int Cross(const Vector a,const Vector b){return a.x*b.y-a.y*b.x;}
    bool cmp (const Vector a,const Vector b) {return a.x==b.x?a.y<b.y:a.x<b.x;}
    Point p[MAXN],s[MAXN];
    int ConvexHull(){
        sort(p,p+n,cmp); //x从小到大,y从小到大;
        int m=0;
        for (int i=0;i<n;i++){
            for (;m>=2 && Cross(s[m-1]-s[m-2],p[i]-s[m-1])<=0;m--);
            s[m++]=p[i];
        }
        int k=m;
        for (int i=n-2;i;i--){
            for (;m>=k+1 && Cross(s[m-1]-s[m-2],p[i]-s[m-1])<=0;m--);
            s[m++]=p[i];
        }
        return m;
    }

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    int m = ConvexHull();
    int cnt = 1, ans = 0;
    for (int l = 0, r = 0; l < m; l++, cnt--) {
        for (; ; r = (r + 1) % m, cnt++) {
            if (Cross(s[l] - s[(l + m - 1) % m], s[r] - s[(r + 1) % m]) < 0) ans = max(ans, cnt);
            else break;
        }
    }
    cout << m - ans << endl;
    return 0;
}