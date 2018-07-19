#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define MAXX_N 100

int t,h,w,key[27],visited[MAXX_N+1][MAXX_N+1];
char building[MAXX_N+1][MAXX_N+1];
string str;

int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

bool ispossible(int y,int x){
    return x>=0&&y>=0&&x<w&&y<h;
}

int main(){
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d%d",&h,&w);
        memset(key,0,sizeof(key));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>building[i][j];
            }
        }
        cin>>str;
        if(str[0]!='0'){
            for(int i=0;i<str.length();i++)
                key[str[i]-'a']=1;
        }
        queue<pair<int,int>> qu;
        queue<pair<int,int>> door[27];
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(i==0||j==0||i==h-1||j==w-1){
                    if(building[i][j]!='*')
                        qu.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        while(!qu.empty()){
            int hy=qu.front().first;
            int hx=qu.front().second;
            qu.pop();
            char c=building[hy][hx];
            if(c=='$'){
                ans++;
                building[hy][hx]='.';
            }
            
            else if(c>='A'&&c<='Z'){
                if(key[c-'A'])
                    building[hy][hx]='.';
                else{
                    door[c-'A'].push({hy,hx});
                    continue;
                }
            }
            else if(building[hy][hx]>='a'&&building[hy][hx]<='z'){
                key[c-'a']=1;
                building[hy][hx]='.';
                while(!door[c-'a'].empty()){
                    qu.push({door[c-'a'].front().first,door[c-'a'].front().second});
                    door[c-'a'].pop();
                }
            }
            for(int i=0;i<4;i++){
                int ny=hy+dy[i];
                int nx=hx+dx[i];
                if(building[ny][nx]=='*') continue;
                if(!visited[ny][nx]&&ispossible(ny,nx)){
                    qu.push({ny,nx});
                    visited[ny][nx]=1;
                }
            }
        }
        printf("%d\n",ans);
    }
}
