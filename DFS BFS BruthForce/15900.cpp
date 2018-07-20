#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAXX_N 500000

int n,deg[MAXX_N+1],visited[MAXX_N+1];
vector<vector<int>> vt;
queue<int> qu;

int bfs(){
    int ret=0;
    int cnt=0;
    qu.push(1);
    visited[1]=1;
    while(int s=qu.size()){
        while(s--){
            int here=qu.front();
            qu.pop();
            if(here!=1&&deg[here]==1)
                ret+=cnt;
            
            for(int i=0;i<vt[here].size();i++){
                int there=vt[here][i];
                if(!visited[there]){
                    qu.push(there);
                    visited[there]=1;
                }
            }
        }
        cnt++;
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    vt.resize(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vt[x].push_back(y);
        vt[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    if(bfs()%2) puts("Yes");
    else puts("No");
    
}
