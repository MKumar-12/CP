// Array pairs divisible by k
//T.C. O(n)
//S.C. O(n)

#include<bits/stdc++.h>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    unordered_map<int,int> modulo;      

    // mod[-1 % 3] = mod[(-1 + 3) % 3] = mod[2 % 3] = 2
    // ensuring that modulo remains +ve regardless of -ve no.
    for(auto i : arr) 
        modulo[(i%k + k) % k]++;

    if(modulo[0] % 2 != 0)
        return false;
    
    for(int i = 1; i <= k/2; i++) {
        if(modulo[i] != modulo[k-i])
            return false;
    }

    return true;
}

int main()
{
    int temp, k;
    cout<<"\nEnter value for k : ";
    cin>>k;

    vector<int> nums;
    cout<<"\nEnter the no. in arr.(use a non-numeric character to stop, i.e. \",\") :"<<endl;
    while(cin>>temp) {
        nums.push_back(temp);
        
        //chk for non-numeric char. to stop i/p
        if(!cin.good()) {
            cin.clear();        //clear the error flag
            string dummy;
            cin>>dummy;         //consume the non-numeric char.
            break;
        }
    }

    if(canArrange(nums, k))
        cout<<"\nGiven array can be split into pairs whose sum would be divisible by k!";
    else
        cout<<"\nUnable to split array into pairs having sum divisible by k!";
    return 0;
}