#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=4e5;
const double eps=1e-8;
const int mo=1e9+7;
int sum[maxn];
int32_t main()
{
    sum[0]=1;
    int temp=10;
    for(int i=1;i<maxn;i++)
    {
        (sum[i]=sum[i-1]+temp)%=mo;
        (temp*=10)%=mo;
    }
    int n;
    while(cin >> n)
    {
        int p=0,a=0,b=0,z=0;
        for(int i=0; i<n; i++)
        {
            char c;
            cin >> c;
            int x=c-'0';
            (b=x*sum[i]+b)%=mo;
            (a=a*10+z*10)%=mo;
            (z=z*10+x)%=mo;
            (p=p*10+x*i*(i+1)/2+a+b)%=mo;
        }
        cout << p<<endl;
    }
}