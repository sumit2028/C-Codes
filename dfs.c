//program to print DFS order of a graph 

#include <stdio.h>
int g[20][20] = {0};
int out[20];
int k=0;
int n;
void addEdge(int x,int y){
    g[x][y] = 1;
    g[y][x] = 1;
}

int dfs_v(int s,int *pi,int *visit){
    visit[s] = 1;
    printf(" %d ",s);
    out[k++] = s;
    int i=0;
    for(i=0;i<n;i++){
        if(visit[i] == 0 && g[s][i] !=0 ){
            pi[i] = s;
            dfs_v(i,pi,visit);    
        }
    }
    return 0;

}
int dfs(int s){
    int pi[20];
    int visit[20];
    
    int i=0;
    k=0;
    for(i=0;i<n;i++){
        visit[i] = 0;
        pi[i] = s;
        out[i] = 0;
    }
    dfs_v(s,pi,visit); // starting dfs froom source s 
    for(i=0;i<n;i++){
        if(visit[i] == 0){
            dfs_v(i,pi,visit);
        }
    }
    printf("\n pi: ");
    
    for(i=0;i<n;i++){
        printf(" %d ",pi[i]);
        
    }    
    
    printf("\n out :");
    for(i=0;i<n;i++){
        printf(" %d ",out[i]);
        
    }
    
    printf("\n rev Order Path print : \n ");
    
    int j;
    for(i=0;i<n;i++){
        if(i==s) continue;
        j=i;
        printf("%d ",j);
        while(j!=s){
         
            j=pi[j];
            printf(" <-- %d ",j);
        }   
    
        printf("\n ");  
    }  
     
    printf("\n ");
    
    return 0;
}
int main(){

    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(0,3);
    addEdge(1,4);
    addEdge(2,4);
    
    n = 5;
    //dfs(0);
    int i;
    for(i=0;i<n;i++){
        printf ("starting point : [%d]  ",i);
        dfs(i);
    }
    return 0;
}
