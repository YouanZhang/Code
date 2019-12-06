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
int m[11];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        int l;
        cin >> s >> l;
        if (s[0] == 'f') {
            for (int j = 0; l; j++, l >>= 1) m[j] += (l & 1);
        }
        else {
            int M = 0;
            for (; M < 11; M++) 
                if (m[M] && pow(2, M) >= l) break;
            if (M == 11) {
                cout << "ERROR!" << endl;
                continue;
            }
            m[M]--;
            M = pow(2, M);
            l = M - l;
            for (int j = 0; l; j++, l >>= 1) m[j] += (l & 1);
        }
        for (int j = 0; j < 11; j++) {
            if (m[j] < 0) m[j + 1]--, m[j] += 2;
            cout << m[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}