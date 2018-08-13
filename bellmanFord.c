// program for single source shortest path in a graph which have negative weight also 
// working 
#include <stdio.h>
/*
// loop in graph 
int g[4][4]={
            {0,2,0,5},
            {0,0,3,-3},
            {0,0,0,4},
            {0,-2,0,0}};

int n=4;
*/
int g[][5]={{0,6,0,0,7},
           {0,0,5,-4,8},
           {0,-2,0,0,0},
           {2,0,7,0,0},
           {0,0,-3,9,0}};
           
int n=5;

int k=0;
int edge[10][2];
int dist[10];
int pi[10];



void printinfo(void){
    printf("valu k %d\n",k);
    int i;
    for(i=0;i<k;i++){
      
        printf("%d,%d --> %d \n",edge[i][0],edge[i][1],g[edge[i][0]][edge[i][1]]);
       
     }  
     return ;
}
int bellman(int s){
    //printinfo();
    int i,j;
    for(i=0;i<n;i++){
        pi[i] = s;
        dist[i] = 99999;
        
    } 
    dist[s] = 0;
    
    
    for(i=0;i<n-1;i++){
        for(j=0;j<k;j++){
            int u,v;
            u = edge[j][0];
            v = edge[j][1];
            if(dist[u] != 99999 && (dist[v] > (dist[u] + g[u][v]))){
                dist[v] = dist[u] + g[u][v];
                pi[v] = u;
            }
        }    
        /*  
        printf("\ni :%d\n",i);
        for(j=0;j<n;j++){
            printf("%3d",dist[j]);
        }
        */
        
    }    
    
    for(j=0;j<k;j++){
        int u,v;
        u = edge[j][0];
        v = edge[j][1];
        if(dist[v] > (dist[u] + g[u][v])){
            printf("Negative Cycle found !!\n");
            return 0;
                
        }
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
    
    int i,j;
   
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(g[i][j]!=0){
                edge[k][0] = i;
                edge[k][1] = j;
                k++;
            }
            else
                g[i][j] = 99999;
        }
    }
     
    bellman(0);
}
