#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 4e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
P a[MAXN], h[MAXN];
LL n, x;
int lowbit(int x) {
  return x & -x;
}
void updata(int x)
{
	int lx, i;
	while (x <= n)
	{
		h[x] = a[x];
		lx = lowbit(x);
		for (i=1; i<lx; i<<=1)
			h[x] = max(h[x], h[x-i]);
		x += lowbit(x);
	}		
}
P min(P a, P b) {
    if (a.first == b.first) {
        if (a.second < b.second) return a;
        else return b;
    }
    else {
        if (a.first < b.first) return a;
        else return b;
    }
    return a;
}
int query(int x, int y)
{
	int ans = 0;
	while (y >= x)
	{
		ans = min(a[y], ans);
		y --;
		for (; y-lowbit(y) >= x; y -= lowbit(y))
			ans = min(h[y], ans);
	}
	return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> x;
    for (int i = 0; i < x; i++) {
        a[i] = P(0, i);
        updata(i);
    }
    for (int i = 1; i <= n; i++) {
        LL y;
        cin >> y;
        a[y % x].first++;
        updata(i);
        P ans = query(0, x);
    }
    return 0;
}