#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b ? a : b)

int MemoLIS(int ** dp , int *arr , int n){
    if(n < 0) return 0;

    if((*dp)[n] != 0){
        return (*dp)[n];
    }

    if(n == 0){
        (*dp)[n] = 1;
    }
    else{
        int max_lis = 1;
        for(int j = n-1; j >= 0 ; j--){
            if(arr[j] < arr[n])
                max_lis = max(max_lis , MemoLIS(dp,arr,j) + 1);
        }
        (*dp)[n] = max_lis;
    }
    return (*dp)[n];

}

int main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    int * arr = (int *) malloc(sizeof(int) * n);
    int * dp = (int *) malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    

    int max_LIS = 0;
    for(int i = 0 ; i < n ; i++){
        max_LIS = max(max_LIS, MemoLIS(&dp,arr,i));
    }

    printf("Longest Increasing Subsequence : %d\n", max_LIS);


    return 0;
}