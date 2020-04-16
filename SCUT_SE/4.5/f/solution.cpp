#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int MAXN = 1e5 + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI = acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
LL a[MAXN], b[MAXN];
multiset <P> s;
LL cnt[MAXN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
	int N, M;
	cin >> N >> M;
	LL ta = 0, tb = 0;
	int n = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		ta += a[i];
		if (ta <= M) n++;
	}
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
		if (i <= n) s.insert(P(b[i], i));
	}
	ta = 0;
	for (int i = 1, j = 1; i <= N; i++) {
		ta += a[i];
		if (ta > M) break;
		tb += a[i];
		while (j <= n && b[j] < tb) {
			tb -= b[j];
			s.erase(s.find(P(b[j], j)));
			j++;
		}
		if (s.empty()) continue;
		tb -= (*s.rbegin()).first;
		cnt[(*s.rbegin()).second]++;
	}
	int count = 0, t = 0;
	vector <int> ans;
	for (int i = 1; i <= N; i++) {
		t += b[i];
		for (int j = 0; j < cnt[i]; j++) {
			if (t <= M)
				ans.push_back(t);
			t += b[i];
		}
		if (t <= M) count++;
	}
	if (count < n) {
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	else cout << -1 << endl;
}
