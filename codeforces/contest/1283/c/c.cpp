#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[MAXN], in[MAXN];
vector <P> q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) continue;
        in[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            int j = i;
            for (; a[j] != 0; j = a[j]);
            q.push_back(P(i, j));
        }
    }
    for (int i = 0; i < q.size(); i++)
        a[q[i].second] = q[(i + 1) % q.size()].first;
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}