#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], b[MAXN];
bool in[MAXN];
map <int, int> mp;
int q[MAXN];
int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) mp[a[i]] = ++cnt, b[cnt] = a[i];
    }
    for (int i = 1; i <= max(k, n); i++){
        if (in[mp[a[i]]]) continue;
        if (q[0] >= k) in[q[q[0] - k + 1]] = 0;
        in[mp[a[i]]] = 1;
        q[++q[0]] = mp[a[i]];
    }
    cout << min(q[0], k) << endl;
    for (int i = 1; i <= min(q[0], k); i++) cout << b[q[q[0] - i + 1]] << ' ';
    cout << endl;
}