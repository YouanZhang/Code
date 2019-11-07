// Cease to struggle and you cease to live
#include <bits/stdc++.h>
using namespace std;
int n, m, q, K, T;
int get(int size, int be, int goal){
	if (be > size) be = (be - 1) % size + 1;
	if (goal % m == be % m)
		return (goal - be) / m + 1;
	return (size - be) / m + 1 + get(size - (size - be) / m - 1, (be + ((size - be) / m + 1) * m) - size, goal > be ? goal - (goal - be) / m - 1 : goal);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
	for (cin >> T; T; T--){
		cin >> n >> m >> q; m++;
		for (int i = 1; i <= q; i++){
			cin >> K;
			cout << get(n, 1, K) << endl;
		}
	}
    return 0;
}
