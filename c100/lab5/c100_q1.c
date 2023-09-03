#include <stdio.h>
#include <math.h>

int main(void) {
  // START CODE
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i = 0; i < n ; i++)
    scanf("%d", &a[i]);

  int small[3], large[3];

  int ctr = 0;
  for(int j = 0; j<=2; j++){
    int min = -__INT_MAX__;
    int max = __INT_MAX__;
    for(int i = 0; i < n ; i++){
        if(a[i] < min && a[i] < small[j])
            min = a[i];
        if(a[i] > max && a[i] > large[j])
            max = a[i];
    }
    small[ctr++] = min;
    large[ctr++] = max;
  }
  
  for(int j = 0; j<=2; j++)
    printf("%d ", small[j]);

  printf("\n");

  for(int j = 0; j<=2; j++)
    printf("%d ", large[j]);
  // END CODE
  return 0;
}