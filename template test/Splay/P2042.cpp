#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 7;
const int INF = 1e9 + 7;
namespace splay {
    int tcnt, root;
    int sz[MAXN], tr[MAXN][2], fa[MAXN], val[MAXN], sum[MAXN], mxsum[MAXN];
    bool rev[MAXN];
    pair <bool, int> mdf[MAXN];
    int newnode(int w) {
        ++tcnt;
        sz[tcnt] = 1;
        fa[tcnt] = tr[tcnt][0] = tr[tcnt][1] = 0;
        val[tcnt] = sum[tcnt] = w; rev[tcnt] = 0;
        return tcnt;
    }
	void push_up(int v) {
		int l = tr[v][0], r = tr[v][1];
		sz[v] = sz[l] + 1 + sz[r];
        sum[v] = sum[l] + sum[r] + val[v];
	}
	void push_down(int v) {
		if(!v) return;
        if (rev[v]) {
            rev[v] = 0; swap(tr[v][0], tr[v][1]);
            rev[tr[v][0]] ^= 1;
            rev[tr[v][1]] ^= 1;
        }
        if (mdf[v].first) {
            mdf[v].first = 0;
            val[v] = mdf[v].second;
        }
	}
	void rotate(int x) {
		int y = fa[x], z = fa[y];
		push_down(y);push_down(x);
		int lr = tr[y][1] == x;
		if(z) tr[z][tr[z][1]==y] = x; 
		fa[x] = z;
		fa[tr[y][lr] = tr[x][lr^1]] = y;
		fa[tr[x][lr^1] = y] = x;
		push_up(y); push_up(x);
	}
	void splay(int x, int k) {
		for(int y, z; (y = fa[x]) != k; rotate(x)) {
			if((z = fa[y]) != k) {
				if((tr[y][0] == x) ^ (tr[z][0] == y)) 
					rotate(x); else rotate(y);
			}
		}
		if(!k) root = x;
	}
	int find(int x, int rank) {
		push_down(x);
		int l = tr[x][0], r = tr[x][1];
		if(sz[l] + 1 == rank) return x;
		if(sz[l] >= rank) return find(l, rank);
		return find(r, rank - sz[l] - 1);
	}
    int build(int l, int r) {
		if(l > r) return 0;
		if(l == r) {
			int num; scanf("%d", &num);
			return newnode(num);
		}
		int mid = (l + r) >> 1;
		int ls = build(l, mid-1);
		int num; scanf("%d", &num);
		int v = newnode(num);
		int rs = build(mid+1, r);
		if(ls) fa[ls] = v; 
		tr[v][0] = ls;
		if(rs) fa[rs] = v; 
		tr[v][1] = rs;
		push_up(v);
		return v;
	}
    void insert() {
        int pos;
        cin >> pos;
        int x = find(root, pos + 1), y = find(root, pos + 2);
        splay(x, 0); splay(y, x);
        int n;
        cin >> n;
        int z = build(1, n);
        fa[tr[y][0] = z] = y;
        splay(z, 0);
    }
    void delet() {
        int l, r;
        cin >> l >> r;
        r += l - 1;
		int x = find(root, l), y = find(root, r + 2);
		splay(x, 0); splay(y, x);
		tr[y][0] = 0;
        splay(y, 0);
	}
    void modify() {
        int l, r;
        cin >> l >> r;
        r += l - 1;
		int x = find(root, l), y = find(root, r + 2);
		splay(x, 0); splay(y, x);
		int z = tr[y][0];
        int c;
        cin >> c;
        mdf[z] = pair <bool, int> (1, c);
	}
    void reverse() {
        int l, r;
        cin >> l >> r;
        r += l - 1;
        int x = find(root, l), y = find(root, r + 2);
        splay(x, 0); splay(y, x);
        int z = tr[y][0];
        rev[z] ^= 1;
        splay(z, 0);
    }
    int getSum() {
        int l, r;
        cin >> l >> r;
        r += l - 1;
        int x = find(root, l), y = find(root, r + 2);
        splay(x, 0); splay(y, x);
        return sum[tr[y][0]];
    }
    int getMxsum(int n) {
    }
    void init(int n) {
		tcnt = 2;
		tr[root = fa[1] = 2][0] = 1;
		sz[1] = 1; sz[2] = 2;
		val[1] = -INF; val[2] = INF;
        int z = build(1, n);
        fa[tr[1][1] = z] = 1;
        splay(z, 0);
	}
}
int main() {
    int n, m;
    cin >> n >> m;
    splay::init(n);
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (s[2] == 'S') splay::insert();
        if (s[2] == 'L') splay::delet();
        if (s[2] == 'K') splay::modify();
        if (s[2] == 'V') splay::reverse();
        if (s[2] == 'T') cout << splay::getSum() << endl;
        if (s[2] == 'X') cout << splay::getMxsum(n) << endl;
    }
}