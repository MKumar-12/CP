//
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

int Lsearch(int arr[], int n, int x) {           //linear search T.C. O(n)   Unsorted/sorted arr
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int Bsearch(int arr[], int n, int x) {           //binary search T.C. O(log n)  req. Sorted arr
    int start = 0, end = n-1,mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"\nEnter no. of elements : ";         //  6
    cin>>n;
    int arr[n];
    cout<<"\nElements are : ";                  //  1 3 5 8 10 12
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int x,index;
    cout<<"\nEnter the element to be searched : ";
    cin>>x;
    //index = Lsearch(arr,n,x);
    index = Bsearch(arr,n,x);
    if(index == -1)
        cout<<"\nElement not found!!";
    else    
        cout<<"\nElement found at index : "<<index;

    return 0;
}