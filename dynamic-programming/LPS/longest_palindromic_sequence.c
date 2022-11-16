#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a > b  ? a : b);

int LCS(char *s , char * t){
    int n = strlen(s);
    int m = strlen(t);

    int ** dp = (int**) malloc((n+1) * sizeof(int*));
    for(int i = 0 ; i < n+1; i++){
        dp[i] = (int*) malloc((m+1) * sizeof(int));
    }


    for(int i = n-1; i >= 0 ; i--){
        for(int j = m-1; j >=0 ; j--){
            // i is ptr of string s
            // j is ptr of string t
            if(s[i] == t[j]){
                dp[i][j] = dp[i+1][j+1] + 1; 
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}


int main(){
    char str[100], rev_str[100];
    printf("Enter a string : ");
    scanf("%s",str);

    int len = strlen(str);
    for(int j = 0 ; j < len ; j++){
        rev_str[j] = str[len - j - 1];
    }
    rev_str[len] = '\0'; // END-OF-STRING 

    printf("Longest palindromic sequence : %d\n",LCS(str,rev_str));
    return 0;

}