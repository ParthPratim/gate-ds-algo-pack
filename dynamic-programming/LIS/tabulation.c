#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b ? a : b)


int main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    int * arr = (int *) malloc(sizeof(int) * n);
    int * dp = (int *) malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    

    dp[0] = 1;
    for(int i = 1; i < n ; i++){
        dp[i] = 1;
        for(int j = i-1; j >= 0 ; j--){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    printf("Longest Increasing Subsequence : %d\n", dp[n]);


    return 0;
}