#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MAXX_N 50

int n,m,st_x,st_y;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
queue<pair<int,pair<int,int>>> qu;
char miro[MAXX_N+1][MAXX_N+1];
int visited[1<<7][MAXX_N+1][MAXX_N+1];

bool ispossible(int y,int x){
    return x>=0&&y>=0&&x<m&&y<n;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>miro[i][j];
            if(miro[i][j]=='0'){
                st_y=i;
                st_x=j;
            }
        }
    }
    int cnt=0;
    int flag=0;
    visited[0][st_y][st_x]=1;
    qu.push({0,{st_y,st_x}});
    while(int s=qu.size()){
        if(flag) break;
        while(s--){
            int hy=qu.front().second.first;
            int hx=qu.front().second.second;
            int hkey=qu.front().first;
            qu.pop();
            if(miro[hy][hx]=='1'){
                flag=1;
                break;
            }
            for(int i=0;i<4;i++){
                int ny=hy+dy[i];
                int nx=hx+dx[i];
                int nkey=hkey;
                if(!ispossible(ny,nx))
                    continue;
                if(miro[ny][nx]=='#')
                    continue;
                else if(miro[ny][nx]>='a'&&miro[ny][nx]<='f')
                    nkey|=(1<<(miro[ny][nx]-'a'));
                else if(miro[ny][nx]>='A'&&miro[ny][nx]<='F')
                    if(!(nkey&(1<<(miro[ny][nx]-'A'))))
                        continue;
                    
                if(!visited[nkey][ny][nx]){
                    qu.push({nkey,{ny,nx}});
                    visited[nkey][ny][nx]=1;
                }
                
            }
        }
        
        cnt++;
    }
    if(!flag) puts("-1");
    else
        printf("%d",cnt-1);
}
