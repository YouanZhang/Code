#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair<int, char> P;
typedef pair<int, P> PP;
const int MAXN = 2e5 + 7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI = acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
char s[3][MAXN];
int n, diff[MAXN];
bool check() {
    int cnt = 0;
    for (int j = 0; j < n; j++)
        if (s[0][j] != s[1][j]) {
            cnt++;
            if (cnt > 1) return 0;
        }
    cnt = 0;
    for (int j = 0; j < n; j++)
        if (s[0][j] != s[2][j]) {
            cnt++;
            if (cnt > 1) return 0;
        }
    return 1;
}
int main() {
    for (int i = 0; i < 3; i++) scanf("%s", s[i]);
    n = strlen(s[0]);
    vector <int> pos;
    for (int i = 0; i < n; i++) 
        if (s[0][i] != s[1][i]) diff[i] = 1;
    for (int i = 0; i < n; i++) 
        if (s[0][i] != s[2][i]) diff[i] = 1;
    for (int i = 0; i < n; i++)
        if (diff[i]) pos.push_back(i);
    bool flag = 1;
    if (pos.size() > 3) flag = 0;
    int ans = 0;
    P change;
    if (flag) {
        if (check()) ans++, change = P(0, s[0][0]);
        for (int i = 0; i < pos.size(); i++) {
            char t = s[0][pos[i]];
            for (char j = 'a'; j <= 'z'; j++)
                if (j != t) {
                    s[0][pos[i]] = j;
                    if (check()) ans++, change = P(pos[i], j);
                }
            s[0][pos[i]] = t;
        }
        if (pos.size()) flag = ans;
        else ans = 2;
    }
    if (!flag) printf("Impossible\n");
    else if (ans > 1) printf("Ambiguous\n");
    else {
        s[0][change.first] = change.second;
        printf("%s\n", s[0]);
    }
    return 0;
}