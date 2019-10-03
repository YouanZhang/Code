#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
long long L[MAXN];
int main() {
    long long Ca;
    scanf("%d", &Ca);
    for (long long ca = 1; ca <= Ca; ca++){
        long long la, lb, n, m;
        scanf("%lld%lld%lld", &la, &lb, &n);
        m = la;
        for (long long i = 1; i <= m; i++){
            scanf("%lld", &L[i]);
            L[i] += L[i - 1];
        }
        for (long long a = 0, b = 0, i = 1; i <= n; la = a, lb = b, i++){
            a = upper_bound(L + 1, L + 1 + m, la) - L;
            if (la == L[a - 1]) --a;
            b = la - L[a - 1];
            if (a == la && b == lb) break;
        }
        printf("Case #%lld: %lld-%lld\n", ca, la, lb);
    }
}