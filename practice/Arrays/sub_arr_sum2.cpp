//Min size Subarr sum
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    int n=0;
    cout<<"No. of elements : ";
    cin>>n;
    cout<<"\nEnter elements  : \t";
    for (int i = 1; i <= n; i++) {
        int temp;
        cin>> temp;
        nums.push_back(temp);
    }

    for(auto a:nums) 
        cout<<a<<" ";
    
    int target, sum = 0;
    cout<<"\nTarget : ";
    cin>>target;
    int sub_count = nums.size(),temp;
    bool flag = false;
    // for(int i = 0; i<nums.size(); i++) {
    //     sum += nums[i];
    //     sub_count++;
        
    //     if(sum < 0) {
    //         sum = 0;
    //         sub_count = 0;
    //         continue;
    //     }

    //     else if(sum < target)
    //         continue;
        
    //     else if(sum == target)
    //         break;
    // }

    for(int i = 0; i<nums.size(); i++){                         //T.C. O(n^3)
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if(sum == target){
                flag = true;
                temp = 0;
                for(int k = i; k<=j; k++)
                    temp++;    
            }

        }
        sum = 0;
        sub_count = min(temp, sub_count);        
    }

    if(flag)
        cout<<"\n\nMin. Size Subarr. sum equals target : " << sub_count;
    else
        cout<<"\n\nMin. Size Subarr. sum equals target : 0 ";
    return 0;
}
