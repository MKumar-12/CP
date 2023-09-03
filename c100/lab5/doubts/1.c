//
//T.C. 
//S.C. 

#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][n];
    for(int i=0 ; i<n; i++){
        for (int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    }

/* Input

4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/

    int t[n][n];
    for(int i=0 ; i<n; i++){
        for (int j=0; j<n; j++)
            t[j][i] = arr[i][j];
    }

    printf("\nTranspose : \n");
    for(int i=0 ; i<n; i++){
        for (int j=0; j<n; j++)
            printf("%d ", t[i][j]);
        
        printf("\n");
    }

    int ctr = 0;
    for(int i=0 ; i<n; i++){
        for (int j=0; j<n; j++)
            if(arr[i][j] != t[i][j])
                ctr++;
    }

    if(ctr == 0)
        printf("\nYES");
    else    
        printf("\nNO");
    return 0;
}