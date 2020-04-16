#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int MAXN = 500 + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI = acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n;
string s[MAXN];
bool check(string a, string b)
{
    if (a.size() != b.size())
        return false;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            cnt++;
    return (cnt == 2);
}
vector<int> G[MAXN];
int from[MAXN];
int tot;
bool use[MAXN];
bool match(int u)
{
    for (auto v : G[u])
    {
        if (!use[v])
        {
            use[v] = true;
            if (from[v] == -1 || match(from[v]))
            {
                from[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    tot = 0;
    memset(from, 255, sizeof(from));
    for (int i = 1; i <= n; i++)
    {
        memset(use, 0, sizeof(use));
        if (match(i)) {
            ++tot;
            // cerr << i << endl;
        }
    }
    return tot;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j < i; j++)
            if (check(s[i], s[j]))
            {
                G[i].push_back(j), G[j].push_back(i);
                // cerr << i << ' ' << j << endl;
            }
    }
    int ans = hungary();
    cout << ans / 2 + (n - ans) << endl;
    return 0;
}