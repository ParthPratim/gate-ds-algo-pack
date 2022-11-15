#include <stdio.h>
#include <stdlib.h>

void Modify(int ** ptr, int n){
    int *arr = *ptr;
    for(int i = 0 ; i < n ; i++){
        arr[i] = i+1;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    
    int * one_dim = (int*) malloc(n * sizeof(int));

    printf("Enter elements of the array : ");
    for(int i = 0 ; i< n ; i++){
        scanf("%d", &one_dim[i]);
    }

    printf("Array contents : ");
    for(int i = 0 ; i< n ; i++){
        printf("%d ", one_dim[i]);
    }
    printf("\n");

    printf("Passing the array by reference to a function which will convert array to 1-to-n :");

    Modify(&one_dim, n);
    printf("Array contents : ");
    for(int i = 0 ; i< n ; i++){
        printf("%d ", one_dim[i]);
    }
    printf("\n");

    return 0;
}