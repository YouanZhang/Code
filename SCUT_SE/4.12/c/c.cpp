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
int a[MAXN];
queue <int> b[MAXN];
priority_queue <P> pq;
map <int, int> mp;
bool in[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]].push(i);
    }
    for (int i = 1; i <= n; i++) b[i].push(1e9 + i);
    int ans = 0, cntin = 0;
    for (int i = 1; i <= n; i++) {
        if (in[a[i]] == 0) {
            in[a[i]] = 1;
            ans++;
            if (cntin == k) {
                in[mp.begin() -> second] = 0;
                mp.erase(mp.begin());
                // P mx = pq.top(); pq.pop();
                // in[mx.second] = 0;
            }
            else cntin++;
        }
        
        // cerr << endl;
        // cerr << mp.begin() -> first << ' ' << mp.begin() -> second << endl;
        if (mp.find(-b[a[i]].front()) != mp.end()) {
            // cerr << '!' << endl;
            mp.erase(mp[-b[a[i]].front()]);
        }
        // cerr << b[a[i]].front() << endl;
        b[a[i]].pop();
        // cerr << -b[a[i]].front() << ' ' << a[i] << endl;
        // mp[-b[a[i]].front()] = a[i];
        mp.insert(P(-b[a[i]].front(), a[i]));
        // for (int j = 1; j <= n; j++) 
            // if (in[j]) cerr << j << ' ';
        // cerr << endl;
    }
    cout << ans << endl;
    return 0;
}