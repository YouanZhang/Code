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
int a[7][7];
vector <P> car[11];
struct Car {
    bool pla[11];
    P d[11];
    int s[11];
}c;
queue <Car> q;
queue <int> ans;
int n;
int finans = INT_INF;

const LL p1 = 201, p2 = 301, mod1 = 23017, mod2 = 63841;
struct Hash {
    LL a, b;
    void append(Hash pre, int v) {
        a = (pre.a * p1 + v) % mod1;
        b = (pre.b * p2 + v) % mod2;
    }
    void init(string S) {
        a = b = 0;
        for(int i = 0; i < S.size(); i++) append(*this, S[i]);
    }
    bool operator == (const Hash &x) const {
        return a == x.a && b == x.b;
    }
    bool operator < (const Hash &x) const {
        return a < x.a || (a == x.a && b < x.b);
    }
};

void move(int curans) {

    if (curans + 7 - c.d[1].first >= finans) return;
    if (curans + 7 - c.d[1].first > 10) return; // can not move
    if (curans + 7 - c.d[1].first == 10) {
        for (int i = c.d[1].second + 1; i <= 6; i++) {
            if (a[c.s[1]][i]) return;
        }
    }

    for (int i = 1; i <= n; i++) { //init
        if (c.pla[i] == 0) { // row
            if (c.d[i].first - 1 > 0 && a[c.s[i]][c.d[i].first - 1] == 0) { //move left
                c.d[i].first--;
                c.d[i].second--;
                q.push(c);
                ans.push(curans + 1);
                c.d[i].first++;
                c.d[i].second++;
            }
            if (c.d[i].second + 1 <= 6 && a[c.s[i]][c.d[i].second + 1] == 0) { // move right
                c.d[i].first++;
                c.d[i].second++;
                q.push(c);
                ans.push(curans + 1);
                c.d[i].first--;
                c.d[i].second--;
            }
        }
        else { // col
            if (c.d[i].first - 1 > 0 && a[c.d[i].first - 1][c.s[i]] == 0) { //move up
                c.d[i].first--;
                c.d[i].second--;
                q.push(c);
                ans.push(curans + 1);
                c.d[i].first++;
                c.d[i].second++;
            }
            if (c.d[i].second + 1 <= 6 && a[c.d[i].second + 1][c.s[i]] == 0) { // move down
                c.d[i].first++;
                c.d[i].second++;
                q.push(c);
                ans.push(curans + 1);
                c.d[i].first--;
                c.d[i].second--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    // time_t st = clock();
    for (int i = 1; i <= 6; i++) 
        for (int j = 1; j <= 6; j++) {
            cin >> a[i][j];
            car[a[i][j]].push_back(P(i, j));
        }
    for (int i = 1; i <= 10; i++) {
        n++;
        if (car[i].size() == 0) break;
        if (car[i][0].first == car[i][1].first) {
            c.pla[i] = 0; // row
            c.d[i] = P(car[i].begin()->second, car[i].rbegin()->second);
            c.s[i] = car[i][0].first;
        }
        else {
            c.pla[i] = 1; // col
            c.d[i] = P(car[i].begin()->first, car[i].rbegin()->first);
            c.s[i] = car[i][0].second;
        }
    }

    if (c.d[1].second == 6) { //success at first
        cout << c.d[1].second - c.d[1].first + 1 << endl;
        return 0;
    }

    move(0); // init

    while (!q.empty()) {
        c = q.front(); q.pop();
        int curans = ans.front(); ans.pop();
        if (c.d[1].second == 6) { //success
            finans = min(finans, curans + c.d[1].second - c.d[1].first + 1);
        }
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++) a[i][j] = 0;
        for (int i = 1; i <= n; i++) { // build cur a
            if (c.pla[i] == 0) { // row
                for (int j = c.d[i].first; j <= c.d[i].second; j++)
                    a[c.s[i]][j] = i;
            }
            else { // col
                for (int j = c.d[i].first; j <= c.d[i].second; j++)
                    a[j][c.s[i]] = i;
            }
        }

        move(curans);

    }
    if (finans == INT_INF) cout << -1 << endl;
    else cout << finans << endl;
    // cerr << clock() - st << endl;
    return 0;
}