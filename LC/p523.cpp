// Continous subarray sum
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> prefix_sums(n, vector<long long> (n,0));

        for(int i = 0; i < n; i++) {
            int ctr = 0;
            long long sum = 0;
            
            for(int j = i; j < n; j++) {
                sum += nums[j];
                prefix_sums[i][j] = sum;
                ctr++;
                if(ctr >= 2 && prefix_sums[i][j] % k == 0)
                    return true;
            }
        }

        //debugging
        cout<<"\nPrefix sum arr : "<<endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<prefix_sums[i][j]<<" ";
            }
            cout<<"\n";
        }

        return false;
    }
};


int main()
{
    int target; 
    cout<<"\nEnter target value : ";
    cin>>target;

    int n;
    cout<<"\nEnter no. of elements : ";
    cin>>n;

    vector<int> nums;
    int temp;
    cout<<"\nEnter the values : \n";
    for(auto i = 0; i < n; i++) {
        cin>>temp;
        nums.push_back(temp);
    }

    Solution s;
    cout<<"\nThere exists a good subarray s.t #elements >= 2 & sum = "<<target<<" :\n"<<s.checkSubarraySum(nums, target);
    return 0;
}

