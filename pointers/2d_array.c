#include <stdio.h>
#include <stdlib.h>


// A PROGRAM TO CREATE A TWO DIMENSIONAL ARRAY OF SIZE " N X M " 

int main(){

    int n , m;
    scanf("%d%d",&n,&m);
    
    int ** two_dim = (int**) malloc(n * sizeof(int *));

    for(int i = 0 ; i < n ; i++){
        two_dim[i] = (int *) malloc(m * sizeof(int*));
    }

}