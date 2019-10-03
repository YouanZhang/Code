#include <bits/stdc++.h>
using namespace std;
typedef pair <int, double> P;
typedef pair <double, P> PP;
priority_queue <PP, vector<PP>, greater<PP> > q;
const int MAXN = 2e5 + 7;
double a[MAXN];
int main() {
    int Ca;
    scanf("%d", &Ca);
    for (int ca = 1; ca <= Ca; ca++){
        int n, m;
        scanf("%d%d", &n, &m);
        double sum = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &a[i]);
            sum += a[i];
        }
        ans -= 2 * sum * sum / m;
        ans += sum * sum * m / m / m;
        // for (int i = 1; i <= n; i++)
        //     ans -= 2 * a[i] * sum / n;
        while (!q.empty()) q.pop();
        double s = 0;
        for (int i = 1; i <= n; i++) {
            s += a[i] * a[i] / 1;
            q.push(PP(- a[i] * a[i] / 1 + a[i] * a[i] / 2, P(2, a[i] * a[i])));
        }
        for (int i = n + 1; i <= m; i++){
            PP cur = q.top(); q.pop();
            s += cur.first;
            // cerr << s << endl;
            // cerr << cur.first << endl;
            // double x = cur.second.second;
            // cerr << - cur.second.second / cur.second.first + cur.second.second / (cur.second.first + 1) << endl;

            // cerr << "!" << endl;
            q.push(PP(- cur.second.second / cur.second.first + cur.second.second / (cur.second.first + 1), P(cur.second.first + 1, cur.second.second)));
        }
        ans += s;
        ans /= m;
        printf("Case #%d: %.9lf\n", ca, ans);
    }
}