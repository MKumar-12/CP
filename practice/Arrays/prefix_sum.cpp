//Prefix Sum for sub-arrays
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

int main()
{
    int a[4] = {5,4,-1,3};
    int max_sum=0;

    //Prefix Sum
    for(int i = 0; i < 4; i++){                     //T.C. O(n^2)
        int sum = 0;
        //sets sum as 0 when 1st ptr. moves ahead
        for(int j = i; j < 4; j++) {
            //second ptr.
            sum += a[j];
            cout<<"\n"<<sum;
            if(sum > max_sum)
                max_sum = sum;
        }
    }

    cout<<"\nMax. Sub-arr sum is : "<<max_sum;
    return 0;
}