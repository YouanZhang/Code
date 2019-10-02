#include <bits/stdc++.h>
using namespace std;
string s;
int scnt[26];
struct Str{
    string str;
    int id, ans;
    int cnt[26];
}t[20001];
bool cmpsize(Str a, Str b){
    return (int)a.str.size() < (int)b.str.size();
}
bool cmpid(Str a, Str b){
    return a.id < b.id;
}
int main() {
    int Ca;
    //scanf("%d", &Ca);
    cin >> Ca;
    for (int ca = 1; ca <= Ca; ca++) {
        cin >> s;
        int n;
        //scanf("%d", &n);
        cin >> n;
        //for (int i = 1; i <= n; i++) 
        for (int i = 1; i <= n; i++) {
            cin >> t[i].str;
            t[i].id = i; t[i].ans = 0;
            for (int j = 0; j < 26; j++) t[i].cnt[j] = 0;
            for (int j = 0; j < (int)t[i].str.size(); j++)
                t[i].cnt[t[i].str[j] - 'a']++;
        }
        sort(t + 1, t + 1 + n, cmpsize);
        for (int i = 1, m; i <= n; i += m) {
            int len = (int)t[i].str.size();
            for (m = 1; i + m <= n && (int)t[i + m].str.size() == len; m++);
            for (int j = 0; j < 26; j++) scnt[j] = 0;
            for (int j = 0; j < (int)s.size(); j++) {
                scnt[s[j] - 'a']++;
                if (j - len >= 0) scnt[s[j - len] - 'a']--;
                if (j >= len - 1) {
                    for (int k = i; k < i + m; k++) {
                        bool p = 1;
                        for (int l = 0; l < 26; l++)
                            if (scnt[l] != t[k].cnt[l]) {
                                p = 0;
                                break;
                            }
                        if (t[k].str[0] == s[j - len + 1] && t[k].str[len - 1] == s[j] && p) t[k].ans++;
                    }
                }
            }
        }
        sort(t + 1, t + 1 + n, cmpid);
        for (int i = 1; i <= n; i++) printf("%d\n", t[i].ans);
    }
}