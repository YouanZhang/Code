#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair<LL, LL> P;
typedef pair<LL, P> PP;
const int MAXN = 1e5 + 7;
LL a[MAXN], b[MAXN];
multiset <P> mst;
LL cnt[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
	LL N, M;
	cin >> N >> M;
	LL ta = 0, tb = 0;
	LL n = 0;
	for (LL i = 1; i <= N; i++) {
		cin >> a[i];
		ta += a[i];
		if (ta <= M) n++;
	}
	for (LL i = 1; i <= N; i++) {
		cin >> b[i];
		if (i <= n) mst.insert(P(b[i], i));
	}
	ta = 0;
	for (LL i = 1, j = 1; i <= N; i++) {
		ta += a[i];
		if (ta > M) break;
		tb += a[i];
		while (j <= n && b[j] < tb) {
			tb -= b[j];
			mst.erase(mst.find(P(b[j], j)));
			j++;
		}
		if (mst.empty()) continue;
		tb -= (*mst.rbegin()).first;
		cnt[(*mst.rbegin()).second]++;
	}
	LL count = 0, t = 0;
	vector <LL> ans;
	for (LL i = 1; i <= N; i++) {
		t += b[i];
		for (LL j = 0; j < cnt[i]; j++) {
			if (t <= M)
				ans.push_back(t);
			t += b[i];
		}
		if (t <= M) count++;
	}
	if (count < n) {
		cout << ans.size() << endl;
		for (auto i : ans) {
			cout << i << ' ';
		}
        cout << endl;
	}
	else cout << -1 << endl;
}
