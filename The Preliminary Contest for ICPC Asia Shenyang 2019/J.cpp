#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
LL ans[(int) 1e6 + 7];
LL qp(LL a, LL b){
    LL ret = 1;
    for (; b; b >>= 1){
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}
LL inv(LL x){
    return qp(x, mod - 2);
}
int main(){
    int Ca;
    scanf("%d", &Ca);
    for (int i = 1; i <= (int) 1e6; i++) ans[i] = (ans[i - 1] + inv(i)) % mod;
    for (int ca = 1; ca <= Ca; ca++) {
        int n, x;
        scanf("%d%d", &n, &x);
        printf("%lld", (1 + mod - (ans[n] - ans[x])) % mod);
    }
}