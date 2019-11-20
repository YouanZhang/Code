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
vector <P> a[MAXN], q;
int cnt[MAXN], cnt2[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n;
    cin >> n;
    for (int i = 1; i <= n - 2; i++) {
        int qi[3];
        cin >> qi[0] >> qi[1] >> qi[2];
        sort(qi, qi + 3);
        a[qi[0]].push_back(P(qi[1], qi[2]));
        a[qi[1]].push_back(P(qi[0], qi[2]));
        a[qi[2]].push_back(P(qi[0], qi[1]));
        cnt[qi[0]]++; cnt[qi[1]]++; cnt[qi[2]]++;
        cnt2[qi[0]]++; cnt2[qi[1]]++; cnt2[qi[2]]++;
    }
    for (int i = 1; i <= n; i++) 
        if (cnt[i] == 1) {
            cnt[i] += 2;
            break;
        }
    int u, nxtu;
    for (int i = 1; i <= n; i++) 
        if (cnt[i] == 1) {
            u = i;
            break;
        }
    for (int i = 1; i <= n - 3; i++) {
        cout << u << ' ';
        P p = a[u][0];
        cnt[u]--; cnt[p.first]--; cnt[p.second]--;
        if (cnt[p.first] == 1) nxtu = p.first;
        if (cnt[p.second] == 1) nxtu = p.second;
        for (auto q = a[p.first].begin(); q != a[p.first].end(); q++) {
            if ((q->first == u || q->second == u) && (q->first == p.second || q->second == p.second)) {
                a[p.first].erase(q);
                break;
            }
        }
        for (auto q = a[p.second].begin(); q != a[p.second].end(); q++) {
            if ((q->first == u || q->second == u) && (q->first == p.first || q->second == p.first)) {
                a[p.second].erase(q);
                break;
            }
        }
        a[u].clear();
        u = nxtu;
    }
    for (int i = 1; i <= n; i++)
        if (cnt[i]) q.push_back(P(cnt2[i], i));
    sort(q.begin(), q.end());
    for (int i = 2; i >= 0; i--) cout << q[i].second << ' ';
    cout << endl;
    return 0;
}