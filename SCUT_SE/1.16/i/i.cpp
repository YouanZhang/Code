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
const LL LL_INF = 1e12 + 7;
const int MOD = 1e9 + 7;
LL q[MAXN], from[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        LL x;
        cin >> x;
        LL head = 0, tail = 1;
        q[1] = x;
        LL ans = LL_INF, st;
        while (head != tail) {
            x = q[++head];
            if (x < ans) {
                ans = x;
                st = head;
            }
            for (LL i = 10, l = x, r = 0; ; i *= 10) {
                r = x % i;
                l = x / i;
                if (abs(r - l) == x) break;
                q[++tail] = abs(r - l);
                from[tail] = head;
            }
        }
        stack <int> ANS;
        for (int i = st; i != 0; i = from[i]) ANS.push(q[i]);
        cout << ANS.size() << ' ';
        while (!ANS.empty()) {
            cout << ANS.top() << ' ';
            ANS.pop();
        }
        cout << endl;
    }
    return 0;
}