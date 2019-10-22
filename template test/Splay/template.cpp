namespace splay{
	//内存回收池见fhq_treap
	int tcnt, root;
	int sz[MAXN];
	int tr[MAXN][2], fa[MAXN];
	int val[MAXN];
	int newnode(int w) {
		++tcnt;
		sz[tcnt] = 1;
		fa[tcnt] = tr[tcnt][0] = tr[tcnt][1] = 0;
		//val[tcnt] = w;
		return tcnt;
	}
	void push_up(int v) {
		int l = tr[v][0], r = tr[v][1];
		sz[v] = sz[l] + 1 + sz[r];
	}
	void push_down(int v) {
		if(!v) return;
	}
	void init() {
		tcnt = 2;
		tr[root = fa[1] = 2][0] = 1;
		sz[1] = 1; sz[2] = 2;
		//val[1] = -INF; val[2] = INF;//权值平衡树
		//val[1] = val[2] = 0;//位置平衡树
		//1,2为哨兵节点,根据题意也可设置为n+1,n+2或1,n+1
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
			int num;scanf("%d", &num);
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
	void insert(int pos, ...) {
		int x = find(root, pos+1), y = find(root, pos+2);
		splay(x, 0); splay(y, x);
		//int z = newnode(w);//插入一个节点
		//int z = build(1, n);//插入n个节点
		fa[tr[y][0] = z] = y;
		splay(z,0);
	}
	void modifyOrQuery(int l, int r, int v) {
		int x = find(root, l), y = find(root, r + 2);
		splay(x, 0); splay(y, x);
		int z = tr[y][0];
		if(!z) return;
		//标记对本身无效,处理时将z点重新计算
		splay(z,0);
	}
	/*int findValue(int v) {
		int res = root;
		for(int cur = root;cur; res = cur, cur = tr[cur][val[cur] <= v]);
		return res;
	}
	void insert(int w) {
		int y = findValue(w);
		int z = newnode(w);
		fa[tr[y][val[y] <= w] = z] = y;
		splay(z,0);
	}*/
	void display(int v) {
		if(!v) return;
		push_down(v);
		display(tr[v][0]);
		if(val[v]) printf("%d ", val[v]);
		display(tr[v][1]);
	}
}