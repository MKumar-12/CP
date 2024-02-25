//SLiding window/2 ptr. approach
//T.C.  O(n)
//S.C.   

#include <bits/stdc++.h>
using namespace std;

int smallestSubsetWithSum(vector<int> &nums, int n, int target) {
    int sub_count = n+1;
    int local_sum = 0;
    int start = 0, end = 0;
    
    while(end < n) {
        while(local_sum < target && end < n) {
            local_sum += nums[end++];
        }     

        //as soon as sum >= target, update S ptr.
        while(local_sum >= target && start < end) {
            if(end - start < sub_count)
                sub_count = end - start;
            
            local_sum -= nums[start++];
        }   
    }

    return sub_count;
}

int main()
{
    vector<int> nums;
    int n = 0;
    cout<<"No. of elements : ";
    cin>>n;
    cout<<"\nEnter elements  : "<<endl;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin>> temp;
        nums.push_back(temp);
    }

    for(auto a:nums) 
        cout<<a<<" ";
    
    int target,res;
    cout<<"\nTarget : ";
    cin>>target;

    res = smallestSubsetWithSum(nums,n,target);
    if(res == n+1)
        cout<<"No such subarray exists for which sum == target value.";
    else
        cout<<"Min. sized sub-array with sum == target value is : "<<res;
    
    return 0;
}