//Finding max contigous sub-arr sum  
//T.C. O(n)
//S.C. 

#include<iostream>
using namespace std;

int main()
{
    int a[4] = {5,4,-1,3};
    //int max_sum=0;
    // for(int i = 0; i < 4; i++){                     //T.C. O(n^3)
    //     for(int j = i; j < 4; j++) {
    //         int temp = 0;
    //         for(int k = i; k<=j; k++)
    //             temp += a[k];
    //         cout<<"\n"<<temp;
    //         if(temp > max_sum)
    //             max_sum = temp;
    //     }
    // }


    //Prefix Sum
    // for(int i = 0; i < 4; i++){                     //T.C. O(n^2)
    //     int sum = 0;
    //     for(int j = i; j < 4; j++) {
    //         sum += a[j];
    //         cout<<"\n"<<sum;
    //         if(sum > max_sum)
    //             max_sum = sum;
    //     }
    // }


    //Kadane's Algo.                                T.C. O(n)
    int max_sum = a[0];     //if atleast 1 contigous element sum is reqd.
    // ^ can be set as 0,    under NO-CONDITIONS
    int sum = 0;
    for(int i = 0 ; i < 4; i++) {
        sum += a[i];
        max_sum = max(sum, max_sum);
        if (sum < 0)
        {
            sum = 0;
        }   
    }

    cout<<"\nMax. Sub-arr sum is : "<<max_sum;
    return 0;
}