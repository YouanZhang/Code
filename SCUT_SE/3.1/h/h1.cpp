#include<stdio.h>
#include<queue>

using namespace std;

struct cell{
    int i, step;
}s, f, c;
queue<cell> q;

int n, m, d;
char ditu[200000];
int directx[4] = {0,0,1,-1}, directy[4] = {1,-1,0,0};

int main(){
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 0; i < n*m; ++i){
        scanf(" %c", ditu+i);
        if(ditu[i] == 'S')
            s.i = i, s.step = 0;
        if(ditu[i] == 'F')
            f.i = i, f.step = -1;
        if(ditu[i] == 'M'){
            c.i = i;
            c.step = 0;
            q.push(c);
        }

    }

    while(!q.empty()){
        c = q.front();
        q.pop();
            if(c.step < d){
                int x = c.i / m;
                int y = c.i % m;
                for(int i = 0; i < 4 ;++i)
                    if(x + directx[i] >= 0 && x + directx[i] < n && y + directy[i] >= 0 && y + directy[i] < m){
                        cell ic;
                        ic.i = (x + directx[i])*m + y + directy[i];
                        ic.step = c.step+1;
                        if(ditu[ic.i] != 'M' && ditu[ic.i] != 'X'){
                            q.push(ic);
                            ditu[ic.i] = 'X';
                        }
                    }
            }

    }

    if(ditu[s.i] == 'X' || ditu[f.i] == 'X'){
        printf("-1\n");
        return 0;
    }

    ditu[s.i] = 'X';

    q.push(s);
    while(!q.empty()){
        c = q.front();
        q.pop();
        if(c.i == f.i){
            printf("%d\n", c.step);
            return 0;
        }
        int x = c.i / m;
        int y = c.i % m;
            for(int i = 0; i < 4 ;++i)
                if(x + directx[i] >= 0 && x + directx[i] < n && y + directy[i] >= 0 && y + directy[i] < m){
                    cell ic;
                    ic.i = (x + directx[i])*m + y + directy[i];
                    ic.step = c.step+1;
                    if(ditu[ic.i] != 'X' && ditu[ic.i] != 'M'){
                        q.push(ic);
                        ditu[ic.i] = 'X';//入队之后一定要马上把这个点赋值成'X'!!!!
                    }
                }
    }

    printf("-1\n");
    return 0;
}