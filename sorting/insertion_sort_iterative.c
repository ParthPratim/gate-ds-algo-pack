#include <stdin>
#include <stdlib.h>

int getInput(int ** arr){
    int n;
    printf("enter the number of elements : ");
    scanf("%d",&n);
    int * arrx = (int*)malloc(n * sizeof(int));
    *arr = arrx;
    printf("enter the elements : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arrx[i]);
    }
    return n;
}


int main(){
    int * arr;
    int n = getInput(&arr);
    
    return 0;
}