#include <bits/stdc++.h>
using namespace std;
char s[1000007];
int main(){
    int Ca;
    for (scanf("%d",&Ca); Ca; Ca--){
        int a, n;
        scanf("%s", s);
        scanf("%d", &a);
        if (strlen(s) > 1) n = 10;
        else n = s[0] - '0';
        n *= 2;
        printf("%.10f\n",(sqrt(5) / (pow((3.0 + sqrt(5)) / (3.0 - sqrt(5)), n) - 1) + (1 + sqrt(5)) / 2.0) * a);
    }
}