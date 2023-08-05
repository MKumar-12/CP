//Finding the 2 element appearing ODD no. of times.
//All other remaining elements appear even no. of times
//T.C.  O(n)
//S.C.  O(1)

#include<iostream>
using namespace std;

void calc_odd_occurrance(int arr[], int n) {             //Naive Approach    T.C. O(n^2)
    for (int i = 0; i < n; i++)
    {
        int ctr = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                ctr++;
        } 
        if(ctr%2 != 0) 
            cout<<arr[i]<<" "; 
    }  
}

void calc_odd_occurrance_modified(int arr[], int n) {    //Optimized         T.C. O(n)   S.C. O(1)
    int x = arr[0];
    for (int i = 1; i < n; i++)
        x = x ^ arr[i];         //XOR operation
    
    //consider the last set bit of res
    int k = x & (~(x-1));         //gives the last set bit of res
    int res1 = 0, res2 = 0;
    //divide arr into 2 grp, 1 having set bit as 0, n other having it as 1.
    for (int i = 0; i < n; i++)
    {
        if((arr[i]&k) != 0)
            res1 = res1 ^ arr[i];
        else
            res2 = res2 ^ arr[i];
    }
    cout<<res1<<" "<<res2;
}

int main()
{
    int arr[100];
    int n;
    cout<<"\nNo. of elements: ";            //6
    cin>>n;
    cout<<"\nEnter values : ";              //7 3 7 1 7 7
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"\nElements NOT paired are : ";
    //calc_odd_occurrance(arr,n);
    calc_odd_occurrance_modified(arr,n);
    return 0;
}