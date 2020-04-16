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
bool check(int l, int r) {
    for (int i = l, j = r; i <= j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}
int get1(int l, int r) {
    int ret = 1;
    for (int i = l + 1; i <= r; i++)
        if (check(l, i)) ret = i - l + 1;
    return ret;
}
int get2(int l, int r) {
    int ret = 1;
    for (int i = r - 1; i >= l; i--)
        if (check(i, r)) ret = r - i + 1;
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int ca;
    for (cin >> ca; ca; ca--) {
        cin >> s;
        string a = "", b = "";
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (s[i] == s[j]) {
                if (i != j) a += s[i];
                b = s[j] + b;
            }
            else {
                int pre = get1(i, j), suf = get2(i, j);
                if (pre >= suf) {
                    for (int k = i; k < i + pre; k++) a += s[k];
                }
                else {
                    for (int k = j; k > j - suf; k--) b = s[k] + b;
                }
                break;
            }
        }
        cout << a + b << endl;
    }
    return 0;
}