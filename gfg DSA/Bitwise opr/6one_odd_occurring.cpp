//Finding the ONLY element appearing ODD no. of times.
//All other remaining elements appear even no. of times
//T.C.  O(n)
//S.C.  O(1)

#include<iostream>
using namespace std;

int calc_odd_occurrance(int arr[], int n) {             //Naive Approach    T.C. O(n^2)
    for (int i = 0; i < n; i++)
    {
        int ctr = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                ctr++;
        } 
        if(ctr%2 != 0) 
            return arr[i]; 
    }  
}

int calc_odd_occurrance_modified(int arr[], int n) {    //Optimized         T.C. O(n)   S.C. O(1)
    int res = arr[0];
    for (int i = 1; i < n; i++)
        res = res ^ arr[i];         //XOR operation
    return res;
}

int main()
{
    int arr[100];
    int n;
    cout<<"\nNo. of elements: ";            //5
    cin>>n;
    cout<<"\nEnter values : ";              //7 3 7 7 7
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    //cout<<"\nElement NOT paired is : "<<calc_odd_occurrance(arr,n);
    cout<<"\nElement NOT paired is : "<<calc_odd_occurrance_modified(arr,n);
    return 0;
}