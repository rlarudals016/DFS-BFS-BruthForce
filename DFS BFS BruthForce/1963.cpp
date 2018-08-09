#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAXX_N 10000

int t_case,st_point,des_point,isNotprime[MAXX_N+1],visited[MAXX_N+1];
vector<int> isPrime;
vector<vector<int>> vt;

void erathos(){
    for(int i=2;i<=10000;i++){
        if(isNotprime[i]) continue;
        for(int j=2*i;j<=10000;j+=i){
            isNotprime[j]=1;
        }
    }
    isNotprime[1]=1;
}

int main(){
    scanf("%d",&t_case);
    erathos();
    for(int i=1000;i<10000;i++)
        if(!isNotprime[i])
            isPrime.push_back(i);
    vt.resize(MAXX_N+1);
    
    for(int i=0;i<isPrime.size();i++){
        for(int j=i+1;j<isPrime.size();j++){
            string str1=to_string(isPrime[i]);
            string str2=to_string(isPrime[j]);
            int cnt=0;
            for(int i=0;i<4;i++){
                if(str1[i]!=str2[i])
                    cnt++;
            }
            if(cnt==1){
                vt[isPrime[i]].push_back(isPrime[j]);
                vt[isPrime[j]].push_back(isPrime[i]);
            }
        }
    }
    
    while(t_case--){
        queue<int> qu;
        memset(visited,0,sizeof(visited));
        scanf("%d%d",&st_point,&des_point);
        qu.push(st_point);
        int ans=0;
        int flag=0;
        while(int qs=qu.size()){
            
            while(qs--){
                int here=qu.front();
                qu.pop();
                if(here==des_point){
                    flag=1;
                    break;
                }
                for(int i=0;i<vt[here].size();i++){
                    int there=vt[here][i];
                    if(visited[there])
                        continue;
                    visited[there]=1;
                    qu.push(there);
                }
            }
            if(flag)
                break;
            ans++;
        }
        if(flag)
            printf("%d\n",ans);
        else
            printf("Impossible\n");
    }
}
