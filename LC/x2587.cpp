// Rearrange array to maximize prefix score
//T.C. O(n logn)
//S.C. O(1)

#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    
    int ctr = 0;
    long long prefix_sum = 0;
    for(auto i : nums) {
        prefix_sum += i;
        if(prefix_sum <= 0)
            break;
        
        ctr++;
    }
    
    return ctr;
}

int main()
{
    int temp;
    vector<int> nums;
    cout<<"\nEnter the no. in arr.(use a non-numeric character to stop, i.e. \",\") :"<<endl;
    while(cin>>temp) {
        nums.push_back(temp);
        
        //chk  for non-numeric char. to stop i/p
        if(!cin.good()) {
            cin.clear();        //clear the error flag
            string dummy;
            cin>>dummy;         //consume the non-numeric char.
            break;
        }
    }

    cout<<"\nMax. Prefix score is : "<<maxScore(nums);
    return 0;
}


/*
2 -1 0 1 -3 3 -3 ,
*/