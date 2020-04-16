#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const int MAXN = 1e6 + 7;
LL qpow(LL x, LL y) {
    LL res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
LL inverse(LL a) { return qpow(a, mod - 2); }
LL inv[MAXN];
LL s[MAXN];
void init() {
    inv[0] = inv[1] = 1;
    for(LL i = 2; i < MAXN; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (LL i = 1; i < MAXN; i++) {
        s[i] = (i - 1) * inv[2] % mod;
        s[i] += s[i - 1];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(3); cout << fixed;
    init();
    for (int n; cin >> n; ){
        cout << (mod + 1 - s[n] * inv[n] % mod * inv[n] % mod * 2 % mod) % mod << endl;        
    }
}