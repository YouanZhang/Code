#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 2e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n, m;
int tag[MAXN], cnt[MAXN];
vector <int> ans;
int bcc_max;
    struct Edge {
        int to, nxt;
    }e[MAXN << 1];
    int ecnt, head[MAXN];
    int dfs_clock, dfn[MAXN], low[MAXN];

    int is_vertex[MAXN], vbcc_cnt, vbccno[MAXN];              
    vector<int> vbcc[MAXN];                                   
    stack<int> vS;                                            

    int ebcc_cnt, ebccno[MAXN];                               
    stack<int> eS;                                            

    inline void addEdge(int u, int v) {
        e[++ecnt] = (Edge) {v, head[u]}; head[u] = ecnt;
        e[++ecnt] = (Edge) {u, head[v]}; head[v] = ecnt;
    }
    inline void init(int n) {
        ecnt = 1;
        dfs_clock = 0;
        vbcc_cnt = 0;                                         
        ebcc_cnt = 0;                                         
        for(int i = 1; i <= n; ++i){
            head[i] = dfn[i] = low[i] = 0;
            is_vertex[i] = 0;                                 
            vbccno[i] = 0;                                    
            ebccno[i] = 0;                                    
        }
        while(!vS.empty()) vS.pop();                          
    }
    //root's edge = -1;
    void tarjan(int u, int edge) {
        dfn[u] = low[u] = ++dfs_clock;
        int ch = 0;                                           
        vS.push(u);                                           
        eS.push(u);                                           
        for(int i = head[u], v; i; i = e[i].nxt) {
            if(!dfn[v = e[i].to]) {
                tarjan(v, i ^ 1);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dfn[u]) {                        
                    ++ch;                                     
                    if(edge > 0 || ch > 1) is_vertex[u] = 1;  
                    vbcc[++vbcc_cnt].clear();                 
                    vbcc[vbcc_cnt].push_back(u);              
                    for(int x;;){                             
                        x = vS.top();vS.pop();                
                        vbcc[vbcc_cnt].push_back(x);          
                        vbccno[x] = vbcc_cnt;                 
                        if(x == v)break;                      
                    }                                         
                }                                        
            }
            else if(dfn[v] < dfn[u] && i != edge) 
                low[u] = min(low[u], dfn[v]);
        }
        if(dfn[u] == low[u]) {                                 
            ebcc_cnt++;                                       
            for(int v;;) {                                     
                v = eS.top(); eS.pop();                       
                ebccno[v] = ebcc_cnt;                         
                if(v == u) break;                             
            }                                                 
        }                                                     
    }
    void findBCC(int n){
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) tarjan(i, -1);
    }
bool dfs(int u) {
    if (u == vbcc[bcc_max][0]) {
        if (ans.size() == vbcc[bcc_max].size()) return true;
        else return false;
    }
    for (int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        if (tag[v] != 1) continue;
        ans.push_back(v); tag[v] = 0;
        if (dfs(v)) return true;
        ans.pop_back(); tag[v] = 1;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    findBCC(n);
    int limit = ceil(sqrt(n));
    if (vbcc_cnt >= limit) {
        cout << 1 << endl;
        for (int i = 1; i <= vbcc_cnt; i++) cout << vbcc[i][0] << ' '; cout << endl; 
    }
    else {
        cout << 2 << endl;
        for (int i = 1; i <= vbcc_cnt; i++) 
            if (vbcc[i].size() > vbcc[bcc_max].size()) bcc_max = i;
        for (int i = 0; i < vbcc[bcc_max].size(); i++) tag[vbcc[bcc_max][i]] = 1;
        for (int i = head[vbcc[bcc_max][0]], v; i; i = e[i].nxt) {
            v = e[i].to;
            if (tag[v] != 1) continue;
            ans.push_back(v); tag[v] = 0;
            if (dfs(v)) break;
            ans.pop_back(); tag[v] = 1;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' '; cout << endl;
    }
    return 0;
}