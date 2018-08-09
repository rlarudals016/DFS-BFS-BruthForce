#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXX_N 50

int arr[MAXX_N+1];

int main(){
    while(1){
        memset(arr,0,sizeof(arr));
        int t_case;
        scanf("%d",&t_case);
        if(!t_case)
            break;
        
        for(int i=0;i<t_case;i++)
            scanf("%d",&arr[i]);
        
        for(int i=0;i<t_case-5;i++){
            for(int j=i+1;j<t_case-4;j++){
                for(int k=j+1;k<t_case-3;k++){
                    for(int o=k+1;o<t_case-2;o++){
                        for(int x=o+1;x<t_case-1;x++){
                            for(int z=x+1;z<t_case;z++){
                                printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[o],arr[x],arr[z]);
                            }
                        }
                    }
                }
            }
        }
        puts("");
    }
}
