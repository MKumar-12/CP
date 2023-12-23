// NSL
//T.C. 
//S.C. 

/*
    Given an arr. of int., 
    return a new arr., s.t, for every element there is a corresponding SMALLER ELEMENT present onto the LEFT of it.
    or -1 is none exists.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearest_smaller_left(int arr[], int n) {
    vector<int> v;
    stack<int> s;

    for(int i = 0; i <= n-1; i++) {
        while(!s.empty() && s.top() >= arr[i])
                s.pop();

        if(s.empty())
            v.push_back(-1);
        else 
            v.push_back(s.top());

        s.push(arr[i]);
    }

    return v;
}

int main()
{
    int size;
    cout<<"\nEnter no. of elements : ";
    cin>>size;

    int nums[size];
    cout<<"\nElements are : "<<endl;
    for(int i = 0; i<size; i++)
        cin>>nums[i];

    vector<int> res;
    res = nearest_smaller_left(nums, size);

    cout<<"\nNearest Smaller Element towards LEFT of every elements are as follows : "<<endl;
    for(int i = 0; i<size; i++)
        cout<<res[i]<<" ";

    return 0;
}

/*
4
1 3 2 4

-1 1 1 2
*/