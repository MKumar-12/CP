//Prime Factorization
//T.C. Theta(n) Optimized 

#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n) {
    if(n==2 ||n==3)
        return true;
    if(n%2 == 0 || n%3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i+=6)
    {
        if(n%i == 0 || n%(i+2) == 0)
            return false;
    }
    return true; 
}

void prime_fact(int n) {                                //Naive soln. O(n log n)
    int temp;
    for(int i = 2; i<n; i++) {
        if(isPrime(i)) {
            temp = i;
            while(n%temp == 0) {
                cout<<i<<" ";
                temp *=i;
            }
        }
    }
}

void prime_fact_optimized(int n) {                      //x3 times faster than O(sqrt[n])
    while(n%2 == 0) {
        cout<<"2 ";
        n = n/2;
    }
    while(n%3 == 0) {
        cout<<"3 ";
        n = n/3;
    }
    for(int i = 5; i <=sqrt(n); i+=6)
    {
        while(n%i == 0){
            cout<<i<<" ";
            n = n/i;
        }
        while(n%(i+2) == 0){
            cout<<(i+2)<<" ";
            n = n/(i+2);
        }
    }
    if(n>3)
        cout<<n;
}

int main()
{
    int n;
    bool res;
    cout<<"Enter a no. : ";
    cin>>n;
    cout<<"\nFollowing are the prime factors of n :\t";
    if(n == 1 || isPrime(n) == true)
        cout<<"1 "<<n;
    else  
        // prime_fact(n);
        prime_fact_optimized(n);
    return 0;
}




/*
==========================================================================
Displaying the count of primes in a no. 
==========================================================================
int main(void) {

  // START CODE
  int n;
  int p_ctr = 0;
  scanf("%d", &n);

  if (n < 2)
    printf("\nNot in valid range");

  else {
    int temp = n;
    int ctr = 0;
    // factor 2
    while (temp % 2 == 0 && temp > 0) {
      ctr++;
      temp = temp / 2;
    }
    if (ctr == 1) {
      printf("2: %d time\n", ctr);
      p_ctr++;
    } else if (ctr > 1) {
      printf("2: %d times\n", ctr);
      p_ctr++;
    }

    temp = n;
    ctr = 0;
    // factor 3
    while (temp % 3 == 0 && temp > 0) {
      ctr++;
      temp = temp / 3;
    }
    if (ctr == 1) {
      printf("3: %d time\n", ctr);
      p_ctr++;
    } else if (ctr > 1) {
      printf("3: %d times\n", ctr);
      p_ctr++;
    }

    temp = n;
    ctr = 0;
    // factor 5
    while (temp % 5 == 0 && temp > 0) {
      ctr++;
      temp = temp / 5;
    }
    if (ctr == 1) {
      printf("5: %d time\n", ctr);
      p_ctr++;
    } else if (ctr > 1) {
      printf("5: %d times\n", ctr);
      p_ctr++;
    }

    temp = n;
    ctr = 0;
    // factor 7
    while (temp % 7 == 0 && temp > 0) {
      ctr++;
      temp = temp / 7;
    }
    if (ctr == 1) {
      printf("7: %d time\n", ctr);
      p_ctr++;
    } else if (ctr > 1) {
      printf("7: %d times\n", ctr);
      p_ctr++;
    }
  }

  printf("Total distinct prime factors: %d", p_ctr);

  // END CODE
  */