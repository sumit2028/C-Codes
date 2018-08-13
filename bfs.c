//program to print BFS order of a graph 
// pi print parent of corresponding node
// out is output array  

#include <stdio.h>
int g[20][20] = {0};
int out[20] = {0};
int k=0;
int n;
void addEdge(int x,int y){
    g[x][y] = 1;
    g[y][x] = 1;
}

int Q[20*20] = {0};
int f = 0,r =0;

void enqu(int x){
    //r++;
    Q[r++] = x;
}

int dequ(){
    
    return Q[f++];
}

int isempty(){
    return (f==r);
}
void clear(){
    f=0;
    r=0;
}
int bfs(int s){
    int pi[20];
    int visit[20];
    
    int i=0;
    k=0;
    for(i=0;i<n;i++){
        visit[i] = 0;
        pi[i] = s;
        out[i] = 0;
    }
    
    enqu(s);
    visit[s] = 1;
   
    while(!isempty()){
        int t = dequ();
        //printf(" %d ",t);
        out[k++] = t; // storing output int out array 
        
        for(i=0;i<n;i++){
            if(visit[i] == 0 && g[t][i] == 1 ){
                visit[i] = 1;
                pi[i] = t;
                enqu(i);
                
            }
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
    
    bfs(0);// starting from node 0 
    
    /*int i;
    for(i=0;i<n;i++){
        printf ("starting point : [%d]  ",i);
        bfs(i);
        clear();
    }
    */
    return 0;
}
