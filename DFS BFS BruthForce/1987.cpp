#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXX_N 20

int n,m,ans,check[27];
char board[MAXX_N+1][MAXX_N+1];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool ispossible(int y,int x){
    return x>=0&&y>=0&&x<m&&y<n;
}

void dfs(int y,int x,int cnt){
    ans=max(ans,cnt);
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!ispossible(ny,nx)||check[board[ny][nx]-'A'])
            continue;
        check[board[ny][nx]-'A']++;
        dfs(ny,nx,cnt+1);
        check[board[ny][nx]-'A']--;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    check[board[0][0]-'A']=1;
    dfs(0,0,1);
    printf("%d",ans);
}
