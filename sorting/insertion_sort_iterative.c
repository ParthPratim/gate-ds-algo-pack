#include <stdio.h>
#include <stdlib.h>


void Insertion_Sort(int ** arrx, int n){
    int * arr = *arrx;
    for(int i = 0 ; i < n ; i++){
        int key = arr[i];
        int j = i-1;

        // skip all elements on right of key which are bigger than it, and place it in it's correct position
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j]; // move each element bigger that key to it's right, to make place for the key
            j--;
        }

        // Now, j+1 is the correct index of key
        arr[j+1] = key;
    }
}

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
    Insertion_Sort(&arr,n);
    for(int i = 0 ; i < n ; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}