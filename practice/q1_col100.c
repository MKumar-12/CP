// Tressure Hunt
//T.C. 
//S.C. 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int N,E,S,W;

    int temp = n;
    W = temp%10;
    E = (temp/10) % 10;
    S = (temp/100) % 10;
    N = (temp/1000) % 10;
    
    int instructors;
    scanf("%d", &instructors);

    int total_dist = 0, displacement;

    int x=0, y=0;    // coordinates of team in X-Y plane
    for(int i = 0; i<instructors; i++){
        int dir, dist;
        scanf("%d %d", &dir, &dist);
        
        total_dist += dist;

        switch (dir)
        {
        case 4 : x -= dist;         //W
                 break;
        case 1 : x += dist;         //E
                 break;
        case 2 : y -= dist;         //S
                 break;
        case 3 : y += dist;         //N
                 break;
        default: printf("Incorrect input");
                 exit(0);
        }
    }  

    displacement = sqrt(pow(x,2) + pow(y,2));

    int quad;

    if(x >= 0 && y > 0)                 // 1st quad
        quad = 1;
    else if( x > 0 && y < 0)            // 4th quad
        quad = 4;
    else if( x < 0 && y < 0)            // 3rd quad
        quad = 3;
    else if( x < 0 && y > 0)            // 2nd quad
        quad = 2;
    else                                // None
        quad = -1;


    printf("\nFinal coordinates of team : (%d, %d)", x,y);
    printf("\nDistance Travelled : %d",total_dist);
    printf("\nDisplacement : %d", displacement);
    printf("\nQuadrant : %d", quad);
    return 0;
}


/*

Sample Input :  

3214
5
3 20
1 40
2 10
4 40
2 40 

*/