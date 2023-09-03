#include <stdio.h>
#include <stdbool.h>

int main(void) {
  /*
    Write a C program that checks whether a given square matrix is
    symmetric or not. A matrix is symmetric if it is equal to its transpose.

    - eg. input
    4
    1 2 3 4
    2 5 6 7
    3 6 8 9
    4 7 9 10
    - eg. output
    YES

    - Don't output anything apart from the final answer.
    - Test your code for given testcases and submit main.c file on
    gradescope
  */
  // START CODE

  int m,n;
  scanf("%d %d", &m,&n);

  int arr[m][n];
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      scanf("%d", &arr[i][j]);
    }
  }
/*
3 3
1 2 3
4 5 6
7 8 9

3 3
1 2 3
2 5 6
3 6 9
*/   
  bool symm = true;
  for(int i = 0; i<m; i++){
    for(int j = 0; j<n; j++){
      if(arr[i][j] != arr[j][i])
        symm = false;
    }
  }
  
  if(symm)
    printf("YES");
  else
    printf("NO");
  // END CODE
  return 0;
}