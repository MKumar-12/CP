// Finding Judge
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,vector<int>>> store(n + 1);

        for(auto i : trust) {
            store[i[1]].second.push_back(i[0]);
        }

        int judge = -1;
        for(auto i : store) {
            if(i.second.size() == n-1) {
                judge = i.first;
                break;
            }
        }

        return judge;
    }
};


int main()
{
    Solution s;
    int n;
    cout<<"\nEnter no. of ppl :";
    cin>>n;
    
    vector<vector<int>> trust;
    
    return 0;
}