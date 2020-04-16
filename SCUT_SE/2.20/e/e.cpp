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
vector <int> num;
vector <int> number[2];
string s, t;
int getnum(int l, int r, string &s) {
    for (int i = l; i <= r; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int x = 0;
            for (i; s[i] >= '0' && s[i] <= '9'; i++) x = x * 10 + s[i] - '0';
            num.push_back(x);
        }
    }
    // for (int i = 0; i < num.size(); i++) cerr << num[i] << ' '; cerr << endl;
}
bool work(int l, int r, string &s, int tag) {
    if (s[l] == 'c') {
        int le = 0;
        for (int i = l + 7; i <= r; i++) {
            if (s[i] == '(' || s[i] == '[') le++;
            if (s[i] == ')' || s[i] == ']') le--;
            if (s[i] == ',' && le == 0) {
                if (!work(l + 7, i - 1, s, tag)) return false;
                if (!work(i + 1, r - 1, s, tag)) return false;
                break;
            }
        }
        return true;
    }
    num.clear();
    getnum(l, r, s);
    if (s[l] == 's' && s[l + 1] == 'h') {
        bool flag = 1;
        for (int i = 1; i < num.size(); i++)
            if (num[i] != num[i - 1]) {
                flag = 0;
                break;
            }
        if (!flag) return false;
    }
    if (s[l] == 's' && s[l + 1] == 'o') {
        sort(num.begin(), num.end());
    }
    for (auto i : num) number[tag].push_back(num[i]);
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> s >> t;
    if (!work(0, s.size() - 1, s, 0) || !work(0, t.size() - 1, t, 1) || number[0].size() != number[1].size()) cout << "not equal" << endl;
    else {
        bool flag = 1;
        // for (int i = 0; i < number[0].size(); i++) cerr << number[0][i] << ' '; cerr << endl;
        // for (int i = 0; i < number[0].size(); i++) cerr << number[1][i] << ' '; cerr << endl;
        for (int i = 0; i < number[0].size(); i++) 
            if (number[0][i] != number[1][i]) {
                flag = 0;
                break;
            }
        if (!flag) cout << "not equal" << endl;
        else cout << "equal" << endl;
    }
    return 0;
}