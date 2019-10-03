#include <bits/stdc++.h>
using namespace std;
int a[6];
int main() {
    int Ca;
    scanf("%d", &Ca);
    for (int ca = 1; ca <= Ca; ca++){
        for (int i = 1; i <= 5; i++) scanf("%d", &a[i]);
        int n;
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            if (x <= 48) ans += a[1];
            else if (x <= 48 + 8) ans += a[2];
            else if (x <= 48 + 8 + 4) ans += a[3];
            else if (x <= 48 + 8 + 4 + 2) ans += a[4];
            else ans += a[5];
        }
        printf("Case #%d: %lld\n", ca, ans * 10000);
    }
}