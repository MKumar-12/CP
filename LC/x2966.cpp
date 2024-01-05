// Divide array into sub-arrays with max. difference
//T.C. O(n log n)
//S.C. O(n)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    for(int i = 0; i <n/3; i++) {
        int a = nums[i*3 + 0];
        int b = nums[i*3 + 1];
        int c = nums[i*3 + 2];

        if(c-a <= k) {
            vector<int> row;
            row.push_back(a);
            row.push_back(b);
            row.push_back(c);

            res.push_back(row);
        }
        else {
            res.clear();
            return res;
        }
    }

    return res;
}

int main()
{
    vector<int> nums;
    int temp;

    cout<<"\nEnter no. (-1 to stop) : "<<endl;
    while(true) {
        cin>>temp;
        if(temp != -1)
            nums.push_back(temp);
        else
            break;
    }

    int k;
    cout<<"\nEnter max. diff. amongest a subarray (of size 3) that is allowed : ";
    cin>>k;

    vector<vector<int>> ans = divideArray(nums,k);
    if(ans.size() == 0)
        cout<<"\nIt is impossible to split the arr. into sub-arrays such that the diff. amongest the elements is <= "<<k<<"!";
    else {
        cout<<"\n Following is solution set : "<<endl;
        for(auto i : ans) {
            for(auto j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

/*
1 3 4 8 7 9 3 5 1 -1
2

1 3 3 2 7 3 -1
3
*/