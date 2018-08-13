// program for dijkasra Algorithm

#include <stdio.h>
#include <limits.h>

int g[5][5]={
             {0,10,0,0,5},
             {0,0,1,0,2},
             {0,0,0,4,0},
             {7,0,6,0,0},
             {0,3,9,2,0}};
int n;             
int visit[5]={0};
int dist[5] = {0};
int pi[5] = {0};
int dijk(int s){
    int i;
    for(i=0;i<n;i++){
        visit[i] = 0;
        pi[i] = s;
        dist[i] = g[s][i];
    }
    visit[s] = 1;
    dist[s] = 0;
    
    int count = 0;
    while(count<n-1){
        int min = 99999;
        int m=-1;
        for(i=0;i<n;i++){
            if(visit[i] == 0 && min > dist[i]){
                min = dist[i];
                m=i;
            }
        }
        if(m==-1){
            printf ("min not found \n");
            
        }
        
        visit[m] = 1;
        
        for(i=0;i<n;i++){
            if(visit[i] == 0 && dist[i] > min+g[m][i]){
                pi[i] = m;
                dist[i] = min + g[m][i];
            }
        }
        
        count++;
    }
    printf("\n pi: ");
    for(i=0;i<n;i++){
        printf("%d ",pi[i]);
    }
    printf("\ni :  dist \n");
    for(i=0;i<n;i++){
        printf("%2d  %3d\n",i,dist[i]);
    }
    printf("\n path printing \n");
    
    int j;

    for(i=0;i<n;i++){
        if(i==s) continue;
        printf("%d ",i );
        j=i;
        while(j!=s){
            j=pi[j];
            printf("<--%d ",j);
        }
        printf("\n");
    }
    
    return 0;
}
int main(){
    n=5;
    
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(g[i][j] == 0){
                g[i][j] = 99999;
            }
            
        }
    }
    dijk(0);
}
