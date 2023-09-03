#include <stdio.h>

int main(void) {
 int num[25], i = 0 , bits = 0 ,j = 0 , a[25], k , n, count = 0 ,gcd , prime , z  , c[25] ;
while (1) {
    scanf ("%d" , &num[i]) ;
    if (num[i] == -1) 
    break ;
    i++ ; 
    j++ ;
  }
  for (i = 0 ; i < j ; i++ ) 
  {
   a[i] = num[i] ;
    bits = 0 ;
    while (1) 
      {
        if (a[i] % 2 == 1)
        bits++ ;
        if (a[i] == 0) 
          break ;
        a[i] = a[i]/2 ;
      }
    
    for ( int b=1; b <= num[i] ; b++) 
      {
        for (int d = 1; d <= b && d <= num[i] ; ++d) {
          if ( b % d == 0 && num[i] % d == 0 )
           gcd = d ; }
        if ( gcd == 1) 
        count = count + 1 ;
        else count = count ;
      }
     c[i]  = num[i] + 1 ;
    if (c[i] % 2 != 0) 
       prime = 0 ;
     while ((c[i]) % 2 == 0) {
     c[i] = c[i] / 2 ;
       while( z > 2 ) {
         if (c[i] % z == 0 && c[i] % 2 == 0 && z != c[i] )
           prime = 0 ;
         else prime = 1 ;
       }
     }
  printf ("(%d,%d,%d)\n" , bits , count , prime ) ;
  } 
  return 0 ;
}