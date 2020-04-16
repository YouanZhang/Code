#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 3e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n, s[MAXN];
P tree[MAXN];
int lowbit(int x) {return x & -x;}
void update(int i,int d)
{
    int id = i;
    s[i]=d;
    while(i<=n)
    {
        if (d > tree[i].first) {
            tree[i] = P (d, id);
        }
        i+=lowbit(i);
    }
}
P query(int l,int r)
{
    P ans = P (s[r], r);
    while(l!=r)
    {
        //剩余部分够一个区间+一个点
        for(--r;r>=l+lowbit(r);r-=lowbit(r))
        {
            if (tree[r].first > ans.first)
            ans = tree[r];//砍一个区间
        }
        //剩余部分不够一个区间+一个点
        if (s[r] > ans.first) ans = P(s[r], r);//一个点一个点的砍直到r=l，通过for循环中--r去递减。
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        P cur = query(1, x);
        cout << cur.first << ' ';
        update(cur.second, 0);
    }
    return 0;
}