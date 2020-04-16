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
int n, m, q;
map <string, int> mp;
int t[MAXN];
int lowbit(int x) {return x & -x;}
void add(int x, int k)
{
    while (x <= n)
    {
        t[x] = t[x] + k;
        x = x + lowbit(x);
    }
}
int getsum(int x)
{
    int ans = 0;
    while (x >= 1)
    {
        ans = ans + t[x];
        x = x - lowbit(x);
    }
    return ans;
}
string d[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) {
        string s;
        int v;
        cin >> s >> v;
        mp[s] = v;
    }
    for (int i = 1; i <= n; i++) 
        add(i, mp[d[i]]);
    for (int i = 1; i <= q; i++) {
        int typ; cin >> typ;
        if (typ == 1) {
            int x; string y;
            cin >> x >> y;
            add(x, mp[y] - (getsum(x) - getsum(x - 1)));
        }
        else {
            int l, r;
            cin >> l >> r;
            if ((getsum(r) - getsum(l - 1)) * 2 <= (r - l + 1) * 60) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}