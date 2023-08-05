//Trailing Zeroes in factorial of n
//T.C = theta(log n base-5)

#include<iostream>
#include<math.h>
using namespace std;
int tzeroes(int x){
    int r2 = 0, r5 = 0, i = 1, j = 1;                        //Calculate the pair of 2's and 5's in factorial
    int tp = x;
    while(tp/pow(2,i) > 0)                                  //no. of 2's will always be more than no. of 5's, and can be skipped
    {
        r2 += tp/pow(2,i);
        i++;
    }
    tp = x;
    while(tp/pow(5,j) > 0)
    {
        r5 += tp/pow(5,j);
        j++;
    }
    return min(r2,r5);

    /*          OR
        int r5 = 0;         
        for(int i =5; i <= n; i=i*5){                       // T.C = theta(log n base-5)
            r5 += n/i;
        }
        return r5;
    */
}

int main(){
    cout<<"Enter a no. : ";
    int n,res;
    cin>>n;
    res = tzeroes(n);
    cout<<"\nNo. of trailing Zeroes in "<<n<<"! is : "<<res;
    return 0;
}