#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;
namespace splay {
    int tcnt, root;
    int sz[MAXN];
    int tr[MAXN][2], fa[MAXN];
    int val[MAXN];
    bool tag[MAXN];
	void push_up(int v) {
		int l = tr[v][0], r = tr[v][1];
		sz[v] = sz[l] + 1 + sz[r];
	}
	void push_down(int v) {
		if(!v || !tag[v]) return;
        tag[v] = 0; swap(tr[v][0], tr[v][1]);
        tag[tr[v][0]] ^= 1;
        tag[tr[v][1]] ^= 1;
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
    int build(int f, int l, int r) {
        if (l > r) return 0;
        int mid = (l + r) >> 1;
        int node = ++tcnt;
        val[node] = mid; fa[node] = f; sz[node] = r - l + 1;
        tr[node][0] = build(node, l, mid - 1);
        tr[node][1] = build(node, mid + 1, r);
        return node;
    }
    void init(int n) {
        root = build(0, 1, n);
        int x;
        for (x = root, sz[x]++; tr[x][0]; x = tr[x][0], sz[x]++);
        tr[x][0] = ++tcnt; fa[tcnt] = x; val[tcnt] = 0; sz[tcnt] = 1;
        for (x = root, sz[x]++; tr[x][1]; x = tr[x][1], sz[x]++);
        tr[x][1] = ++tcnt; fa[tcnt] = x; val[tcnt] = n + 1; sz[tcnt] = 1;
    }
    int find(int x, int rank) {
		push_down(x);
		int l = tr[x][0], r = tr[x][1];
		if(sz[l] + 1 == rank) return x;
		if(sz[l] >= rank) return find(l, rank);
		return find(r, rank - sz[l] - 1);
	}
    void reverse(int l, int r){
        int x = find(root, l - 1), y = find(root, r + 1);
        splay(x, 0); splay(y, x);
        int z = tr[y][0];
        tag[z] ^= 1;
        splay(z, 0);
    }
    void print(int n, int x) {
        if (!x) return;
        push_down(x);
        print(n, tr[x][0]);
        if (val[x] != 0 && val[x] != n + 1) cout << val[x] << ' ';
        print(n, tr[x][1]);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    splay::init(n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        splay::reverse(l + 1, r + 1);
    }
    splay::print(n, splay::root);
}