#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef double DB;
typedef pair <LL, LL> P;
typedef pair <LL, P> PP;
const LL MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const LL MOD = 1e9 + 7;
LL get(LL r[], LL b[], LL g[], LL nr, LL nb, LL ng) {
        LL ans = 0xffffffffffffffff;
        LL R, G, B, pos1, pos2;
        for (LL i = 0; i < nr; i++) {
            R = r[i];
            pos1 = lower_bound(g, g + ng, R) - g;
            if (pos1 != ng) {
                G = g[pos1];
                pos2 = lower_bound(b, b + nb, (LL) ((R + G) / 2 + 0.5)) - b;
                if (pos2 != nb) {
                    B = b[pos2];
                    ans = min(ans, (R - G) * (R - G) + (R - B) * (R - B) + (G - B) * (G - B));
                }
                if (pos2 != 0) {
                    pos2--;
                    B = b[pos2];
                    ans = min(ans, (R - G) * (R - G) + (R - B) * (R - B) + (G - B) * (G - B));
                }
            }

            if (pos1 != 0) {
                pos1--;
                G = g[pos1];
                pos2 = lower_bound(b, b + nb, (LL) ((R + G) / 2 + 0.5)) - b;
                if (pos2 != nb) {
                    B = b[pos2];
                    ans = min(ans, (R - G) * (R - G) + (R - B) * (R - B) + (G - B) * (G - B));
                }
                if (pos2 != 0) {
                    pos2--;
                    B = b[pos2];
                    ans = min(ans, (R - G) * (R - G) + (R - B) * (R - B) + (G - B) * (G - B));
                }
            }
        }
        return ans;
}
LL r[MAXN], g[MAXN], b[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    LL ca;
    for (cin >> ca; ca; ca--) {
        LL nr, ng, nb; 
        cin >> nr >> ng >> nb;
        for (LL i = 0; i < nr; i++) {
            LL x; cin >> x;
            r[i] = x;
        }
        for (LL i = 0; i < ng; i++) {
            LL x; cin >> x;
            g[i] = x;
        }
        for (LL i = 0; i < nb; i++) {
            LL x; cin >> x;
            b[i] = x;
        }
        sort(r, r + nr);
        sort(g, g + ng);
        sort(b, b + nb);
        LL ans = get(r, g, b, nr, ng, nb);
        ans = min(ans, get(r, b, g, nr, nb, ng));
        ans = min(ans, get(g, r, b, ng, nr, nb));
        ans = min(ans, get(g, b, r, ng, nb, nr));
        ans = min(ans, get(b, g, r, nb, ng, nr));
        ans = min(ans, get(b, r, g, nb, nr, ng));
        cout << ans << endl;
    }
    return 0;
}