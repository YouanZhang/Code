#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;
namespace splay{
    int tcnt, root;
    int sz[MAXN];
    int tr[MAXN][2], fa[MAXN];
    int val[MAXN];
    int newnode(int w) {
        ++tcnt;
        sz[tcnt] = 1;
        fa[tcnt] = tr[tcnt][0] = tr[tcnt][1] = 0;
        val[tcnt] = w;
        return tcnt;
    }
    void push_up(int v) {
        int l = tr[v][0], r = tr[v][1];
        sz[v] = sz[l] + sz[r] + 1;
    }
    void push_down(int v) {
        if (!v) return;
    }
    void init() {
        tcnt = 2;
        tr[root = fa[1] = 2][0] = 1;
        sz[1] = 1; sz[2] = 2;
        val[1] = -INF; val[2] = INF;
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y];
        push_down(y); push_down(x);
        int lr = tr[y][1] == x;
        if (z) tr[z][tr[z][1] == y] = x;
        fa[x] = z;
        fa[tr[y][lr] = tr[x][lr ^ 1]] = y;
        fa[tr[x][lr ^ 1] = y] = x;
        push_up(y); push_up(x);
    }
    void splay(int x, int k) {
        for (int y, z; (y = fa[x]) != k; rotate(x)) {
            if ((z = fa[y]) != k) {
                if ((tr[y][0] == x) ^ (tr[z][0] == y))
                    rotate(x); else rotate(y);
            }
        }
        if (!k) root = x;
    }
    int find(int x, int rank) {
        push_down(x);
        int l = tr[x][0], r = tr[x][1];
        if (sz[l] + 1 == rank) return x;
        if (sz[l] >= rank) return find(l, rank);
        return find(r, rank - sz[l] - 1);
    }
    int findValue(int v) {
        int res = root;
        for (int cur = root; cur; res = cur, cur = tr[cur][val[cur] <= v]);
        return res;
    }
    void insert(int w) {
        if(w == 795196) {
            int xx = 0;
        }
        int y = findValue(w);
        int z = newnode(w);
        fa[tr[y][val[y] <= w] = z] = y;
        splay(z, 0);
    }
    void delet(int w) {
        int x, y, z;
        if(w == 795196) {
            //cerr<<root<<" "<<val[root]<<" " << tr[root][0] << " " << tr[root][1] << endl;
            //for(int tmp = 1635;fa[tmp];tmp = fa[tmp])
                //cerr<<"?"<<tmp<<" "<<val[tmp]<< " " << tr[tmp][0] << " "<< tr[tmp][1] << endl;
            //cerr<< endl;
        }
        for (x = root; val[x] != w; x = tr[x][val[x] < w]);
        if(val[x] == 795196) {
            //cerr<<"!!!"<<endl;
        }
        splay(x, 0);
        for (y = tr[x][0]; tr[y][1]; y = tr[y][1]);
        for (z = tr[x][1]; tr[z][0]; z = tr[z][0]);
        splay(y, 0);
        splay(z, y);
        tr[z][0] = 0;
        splay(z, 0);
    }
    int rank(int v) {
        int x = findValue(v - 1);
        splay(x, 0);
        return sz[tr[x][0]] + (val[x] < v);
    }
    int arank(int rank) {
        return val[find(root, rank + 1)];
    }
    int pre(int w) {
        int x = findValue(w - 1);
        splay(x, 0);
        if (val[x] < w) return val[x];
        for (x = tr[x][0]; tr[x][1]; x = tr[x][1]);
        return val[x];
    }
    int suc(int w) {
        int x = findValue(w);
        splay(x, 0);
        if (val[x] > w) return val[x];
        for (x = tr[x][1]; tr[x][0]; x = tr[x][0]);
        return val[x];
    }
}
int main() {
    //freopen("3224_4.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    for (int m; cin >> m; ) {
        splay::init();
        int tag = 0;
        for (int i = 1; i <= m; i++) {
            int opt, x;
            cin >> opt >> x;
            if (opt != 1 && opt != 2) {
                if(++tag == 2731) {
                    int xx = 0;
                }
            }
            if (opt == 1) splay::insert(x);
            if (opt == 2) splay::delet(x);
            if (opt == 3) cout << splay::rank(x) << endl;
            if (opt == 4) cout << splay::arank(x) << endl;
            if (opt == 5) cout << splay::pre(x) << endl;
            if (opt == 6) cout << splay::suc(x) << endl;
        }
    }
}