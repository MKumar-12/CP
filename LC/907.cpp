// Sum of Sub-arr MINIMUMs
//T.C. 
//S.C. 

/*
    #Sub-arr. for n elements :      n(n + 1) / 2
*/


/*
    Brute Force approach :                  T.C.    O(n^2) * O(n) = O(n^3)
        Using 2-ptr.,   
            find all sub-arrays and perform L.S to find min. in each sub-arr. 
            Lastly, perform summation of all such elements.


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
    }
};

int main()
{
    int n;
    vector<int> nums;
    cout<<"\nEnter no. of elements : ";
    cin>>n;

    cout<<"\nEnter values : "<<endl;
    for(int i = 0; i<n; i++) {
        int temp; 
        cin>>temp;
        nums.push_back(temp);
    }

    Solution s;
    cout<<"\n\nSum of Sub-arr. minimums : "<<s.sumSubarrayMins(nums);
    return 0;
}