// post_fix_evaluation.c
// stack in int type 



#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int st[1025];
int t = -1;

int isempty(void);
int isfull(void);
void push(int c);
int pop(void);
int top(void);

void push(int c){

    if(!isfull()){
    	st[++t] = c;
    	return ;
    }
    else{
    	//printf("stack is full!!\n");
    	return;
    }
}
int pop(void){
	int c = -1;
    if(!isempty()){
    	c = st[t--];
    }
    else{
    	//printf("stack is empty!!\n");
    	
    }
    return c;
}

int top(void){
	int c = -1;
	if(!isempty()){
    	c = st[t];
    }
    else{
    	//printf("stack is empty!!\n");
    	
    }
    return c;
}
int isempty(void){
	return (t>-1)?0:1;
}

int isfull(void){
	if(t<1024) return 0;
	return 1;
	//return ((t > 1024) ? 1:0);
}

void clear(){
	t=-1;
}

int postEval(char arr[]){
    int val = 0;
    
	int n = strlen(arr);
    int i;
    for(i=0;i<n;i++){
    	char c = arr[i];
    	//if(c >= '0' && c <= '9'){
        if(isdigit(c)){
    		push(c-'0');// char to int 

    		//out[k++] = c;
    	}
    	else{
    		int y ,x;
    		y = top();
    		pop();
    		x = top();
    		pop();
    		switch(c){
    			case '+': 
    			          push(x+y);
    			          break;
    			case '-': 
    			          push(x-y);
    			          break;
    			case '*': 
    			          push(x*y);
    			          break;
    			case '/': 
    			          push(x/y);
    			          break;                              

    		}
    		
    		}
    	}
    
    printf(" %d %d \n",top(),t);
    
	return top();
}
int main(){
	
    char arr1[]="12+3*";
    printf("\nInfix string :%s \n",arr1);   
    printf ("post Eval  :: %d \n",postEval(arr1));
    char arr2[]="12+34+*";
    printf("\nInfix string :%s \n",arr2);   
    printf ("post Eval  :: %d \n",postEval(arr2));
    clear();
	return 0;
}