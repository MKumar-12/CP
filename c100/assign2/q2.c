//Binary Operators using Conditional statment

#include<stdio.h>

int main()
{
    //2 4-bits no.
    int a[4], b[4];

    //input 1st no.
    for(int i=0; i<4; i++)
        scanf("%d", &a[i]);

    //input 2nd no.
    for(int i=0; i<4; i++)
        scanf("%d", &b[i]);

    /*
       input :
                1 1 0 0
                0 0 1 0 
    */

    
    //ADD result
    int ADD[4], carry = 0;
    printf("\nAddition      : ");
    for(int i=3; i>=0; i--){
        ADD[i] = a[i] + b[i] + carry;
        carry = ADD[i] / 2;
        ADD[i] = ADD[i] % 2;
    }
    
    printf("%d ", carry);
    for(int i=0; i<4; i++)
        printf("%d ", ADD[i]);

    //XOR result
    printf("\nXOR           : ");
    for(int i=0; i<4; i++){
        if(a[i] != b[i])
            printf("1 ");
        else    
            printf("0 ");
    }

    //AND result
    printf("\nAND           : ");
    for(int i=0; i<4; i++)
        printf("%d ", a[i] & b[i]);

    //OR result
    printf("\nOR            : ");
    for(int i=0; i<4; i++)
        printf("%d ", a[i] | b[i]);


    return 0;
}