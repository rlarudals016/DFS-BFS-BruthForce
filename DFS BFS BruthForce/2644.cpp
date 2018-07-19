#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAXX_N 100

int n,m,source,sink,visited[MAXX_N+1];
vector<vector<int>> vt;
queue<int> qu;

int bfs(int num){
    visited[num]=1;
    qu.push(num);
    int ret=0;
    while(int s=qu.size()){
        while(s--){
            int here=qu.front();
            qu.pop();
            if(here==sink)
                return ret;
            for(int i=0;i<vt[here].size();i++){
                int there=vt[here][i];
                if(!visited[there]){
                    qu.push(there);
                    visited[there]=1;
                }
            }
        }
        ret++;
    }
    return ret;
}

int main(){
    scanf("%d%d%d%d",&n,&source,&sink,&m);
    vt.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    int ans=bfs(source);
    if(!visited[sink]) puts("-1");
    else printf("%d",ans);
    
    return 0;
}
