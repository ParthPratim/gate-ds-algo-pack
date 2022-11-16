#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define max(a,b) (a>b ? a : b)

int MemoLCS(int ***dp , char * s , char * t, int n , int m){
    
    if(n == 0 || m == 0){
        (*dp)[n][m] = 0;
        return (*dp)[n][m];
    }
    // The LCS if either(or both) of strings are 0 length, is 0 as nothing is common
    
    if((*dp)[n][m] != -1){
        return (*dp)[n][m];
    }
    // -1 is added to both indices below, as n and m are taken as 1-based indices, 
    // but in reality strings work in 0-based
    
    if(s[n-1] == t[m-1]){
        // take this as part of the LCS
        (*dp)[n][m] = 1 + MemoLCS(dp, s,t, n-1, m-1);
    }
    else{
        (*dp)[n][m] = max(MemoLCS(dp, s,t, n-1, m),MemoLCS(dp, s,t, n, m-1));
    }

    return (*dp)[n][m];

}

int main(){
    char s[100] , t[100];
    scanf("%s",s);
    scanf("%s",t);
    int n = strlen(s);
    int m = strlen(t);

    int ** dp = (int**) malloc((n+1) * sizeof(int*));
    for(int i = 0 ; i < n+1; i++){
        dp[i] = (int*) malloc((m+1) * sizeof(int));
        memset(dp[i],-1,sizeof(int)*(m+1));
    }
    
    printf("Maximum LCS Length : %d \n",MemoLCS(&dp,s,t,n,m)); 
    printf("%d\n",dp[3][2]);
    return 0;
}