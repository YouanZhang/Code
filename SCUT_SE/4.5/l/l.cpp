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
string s;
LL n, len;
int v[66];
LL r() {
    LL ret = 0;
    for (int i = 0; i < len; i++) {
        if (!v[i]) {
            ret <<= 1;
            if(s[i] == '1') ret += 1;
        }
    }
    return ret;
}
int main(){
    cin >> n;
    cin >> s;
    len = s.size();
    int ans = 0;
    while (1) {
        if (r() <= n) break;
        bool tag1 = true;
        for (int i = 1; i < len; i++) {
            if (s[i] == '1' && v[i] == 0) {
                v[i] = 1;
                tag1 = false;
                break;
            }
        }
        if (tag1) {
            for (int i = 1; i < len; i++) {
                if (s[i] == '0' && v[i] == 0) {
                    v[i] = 1;
                    break;
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
}