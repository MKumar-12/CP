#include <stdio.h>

int main(void) {
  // START CODE
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n ; i++)
    scanf("%d", &arr[i]);

  int k;
  scanf("%d", &k);

/*
6
1 2 3 4 5 6
2
*/

  int red[k], ctr = 0, t = 0;
  for(int i = k-1; i >= 0 ; k--){
    red[i] = arr[n-1-t];
    t++;
  }  

  printf("\nReduntant arr : ");
  for(int i = k-1; i >= 0 ; k--)
    printf("\n %d ", red[i]);

  for(int i = 0; i < n ; i++){
    if(i+k% n <= n-1)
        arr[i] = 
  } 

  printf("\nRotated Arr. is  : \n");
  for(int i = 0; i < n ; i++)
    printf("%d ", arr[i]);

  // END CODE
  return 0;
}