//program for permutation and combination 
#include <stdio.h>

int arr[]={1,2,3}; /* input array*/
int visit[10]={0}; /* visited array */
int out[10]={0};   /*  array to print output */ 
int max; /* number of inputs in the input array */

int per(int k,int n); /* function to perform permutation of input array */
int perWR(int k,int n); /* function to perform permutation With Repeatotion of  input array */
int comb(int m,int k,int n);/* function to perform combination of input array */
int combWR(int m,int k,int n);/* function to perform combination With Repeatotion of  input array */

int per(int k,int n){
    int i;
    if(k==n){
        for(i=0;i<n;i++){
            printf("%d",out[i]);
        }
        printf("\n");
        return 0;
    
    }
    /* max is no of items in input array */
    for(i=0;i<max;i++){
        if(visit[i]==0){/*  for "permutation with repeatition" no need for visited array */
            visit[i]=1;
            out[k]=arr[i];
            per(k+1,n);
            visit[i]=0;
        }
    }
    return 0;

}
int comb(int m,int k,int n){
    int i;
    if(k==n){
        for(i=0;i<n;i++){
            printf("%d",out[i]);
        }
        printf("\n");
        return 0;    
    }
    for(i=m;i<max;i++){
        out[k] = arr[i];
        comb(i+1,k+1,n);/* for "combination With Repeatition "  do comb(i,k+1,n)*/
    
    }
    return 0;
}

int perWR(int k,int n){
    int i;
    if(k==n){
        for(i=0;i<n;i++){
            printf("%d",out[i]);
        }
        printf("\n");
        return 0;
    
    }
    for(i=0;i<max;i++){
   
        out[k]=arr[i];
        perWR(k+1,n);
       
    }
    return 0;

}
int combWR(int m,int k,int n){
    int i;
    if(k==n){
        for(i=0;i<n;i++){
            printf("%d",out[i]);
        }
        printf("\n");
        return 0;    
    }
    for(i=m;i<max;i++){
        out[k] = arr[i];
        combWR(i,k+1,n);
    
    }
    return 0;
}  
int main(){
    max = sizeof(arr)/sizeof(arr[0]);
    printf("<--------permutatin ----------------->\n");
    per(0,3);
    /*start permutation from first position and permute 3 items   */
    printf("<--------Combination ----------------->\n");
    comb(0,0,3);
    
    printf("<--------Combination ----------------->\n");
    comb(0,0,2);  /* thitd argument ie 2 , that means taking two element at a time */  
    printf("<--------permutatin WR ----------------->\n");
    perWR(0,3);
    
    printf("<--------Combination WR ----------------->\n");
    combWR(0,0,3);    
    printf("\n");
}
