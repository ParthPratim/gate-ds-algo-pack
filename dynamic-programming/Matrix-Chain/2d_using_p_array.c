#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct 
{
    int rows,cols;
} Matrix;

void Print2DArray(int*** arr , int n){
    int ** arrx = *arr;;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            printf("%d ", arrx[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int n;
    printf("Enter the number of matrices to add : ");
    scanf("%d",&n);

    // Creating a 2D Array of size N X 2 , to store the number of rows and columns for all the n matrices
    Matrix * dims = (Matrix *) malloc((n+1) * sizeof(Matrix));

    int * p = (int* )malloc((n+1) * sizeof(int));

    for(int i = 0 ; i < n ; i++){
        printf("Enter the rows and columns for matrix M%d : ", i+1);
        scanf("%d%d",&dims[i].rows, &dims[i].cols);
        p[i] = dims[i].rows;
        if(i == n-1){ // only for the last matrix, since we have n+1 elements in p array
            p[i+1] = dims[i].cols;
        }
    }

    int ** M, ** S;
    // declaring the M-Table and the S-Table.
    // n+1 is taken so that we can do 1-based indexing from 1-to-N
    M = (int**) malloc((n+1) * sizeof(int*));
    S = (int**) malloc((n+1) * sizeof(int*));
    for(int i = 0 ; i < n+1 ; i++){
        M[i] = (int*) malloc((n+1) * sizeof(int));
        S[i] = (int*) malloc((n+1) * sizeof(int));
    }

    //since, in Matrix chain multiplication, we fill the table diagonally
    for(int diagonal = 1 ; diagonal <= n ; diagonal++){
        int i = 1 , j = diagonal;
        while (i <= n && j <= n)
        {
            if(i == j){
                // Multiplying only one matrix takes 0 operations, as multiplication takes two operands
                M[i][j] = 0;
                S[i][j] = 0;
            }
            else{
                int min_value = INT_MAX;
                int min_k = -1;
                for(int k = i; k < j ; k++){
                    int val = M[i][k] + M[k+1][j] + (p[i-1] * p[k] * p[j]);
                    if(val < min_value){
                        min_value = val;
                        min_k = k;
                    }
                }

                M[i][j] = min_value;
                S[i][j] = min_k; 
            }

            i++;
            j++;
        }       
    }

    printf("M-Table : \n");
    Print2DArray(&M,n);

    printf("\n");

    printf("S-Table : \n");
    Print2DArray(&S,n);

    return 0;
}