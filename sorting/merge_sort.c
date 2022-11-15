#include <stdio.h>
#include <stdlib.h>


void Merge(int ** arr, int l, int r){
    int mid = (l+r)/2;
    int s1 = mid-l+1;
    int s2 = r - mid;
    int *L = (int *) malloc(s1 * sizeof(int));
    int *R = (int *) malloc(s2 * sizeof(int));
    int * arrx = *arr;
    for(int i = 0 ; i < s1 ; i++){
        L[i] = arrx[l+i];
    }
    for(int i = 0 ; i < s2 ; i++){
        R[i] = arrx[mid+1+i];
    }
    int a = 0 , b = 0, c = l;
    while (a < s1 && b < s2)    
    {
        if(L[a] < R[b]){
            arrx[c++] = L[a++];
        }
        else{
            arrx[c++] = R[b++];
        }
    }
    while (a < s1)
    {
        arrx[c++] = L[a++];
    }
    while (b < s2)
    {
        arrx[c++] = R[b++];
    }
}

void MergeSort(int ** arr , int l , int r){
    if(l == r){
        return ;
    }
    else{
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,r);
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
    MergeSort(&arr, 0, n-1);
    printf("Sorted Array : ");
    for(int i = 0 ; i < n ; i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}