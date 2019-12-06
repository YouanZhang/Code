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
double A[11][11], x[11];
int Guass(int n,int m)
{
    int i=1,j=1,k,r,c;
    while(i<=m && j<=n)
    {
        r=i;
        for(k=i+1;k<=m;k++)if(fabs(A[k][j])>fabs(A[r][j]))r=k;
        if(fabs(A[r][j])>=EPS)
        {
            for(c=1;c<=n+1;c++)swap(A[i][c],A[r][c]);
            for(k=i+1;k<=m;k++)if(fabs(A[k][j])>=EPS)
            {
                double f=A[k][j]/A[i][j];
                for(c=j;c<=n+1;c++)
                    A[k][c]-=f*A[i][c];
            }
            i++;
        }
        j++;
    }
    
    for(k=i;k<=m;k++)if(fabs(A[k][n+1])>=EPS)return 0;
    if(i<=n)return 2;
    for(int i=n;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
            A[i][n+1]-=A[i][j]*x[j];
        x[i]=A[i][n+1]/A[i][i];
    }
    
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        int n, m;
        cin >> n >> m;
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> A[j][i];
        if (n > m) {
            cout << "YES" << endl;
            continue;
        }
        m++;
        A[m][1]=1; A[m][n+1]=1;
        cout << (Guass(n, m) ? "YES" : "NO") << endl;
        
    }
    return 0;
}