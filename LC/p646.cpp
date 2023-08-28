//
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> pairs) {
        sort(pairs.begin(), pairs.end());

        cout<<"\n\nSorted Pairs are as follows : "<<endl;
        for(auto it: pairs){
            for(auto j: it)
                cout<<j<<" ";
            cout<<endl;
        }
        
        int max_len = 0;
        for(int i = 0; i < pairs.size(); i++){
            int len = 0;
            int temp = pairs[i][1];
            for(int j = i + 1; j < pairs.size(); j++){
                //matching join condition b < c              {a,b}     {c,d}
                if(temp < pairs[j][0]){
                    len++;
                    temp = pairs[j][1]; 
                }
            }
            if(len > max_len)
                max_len = len;
        }

        return max_len;
    }
};

int main()
{
    vector<vector<int>> pairs = {{7,9},{4,5},{7,9},{-7,-1},{0,10},{3,10},{3,6},{2,3}};
    
    Solution s;

    int len = s.findLongestChain(pairs);
    cout<<"\nLongest len. of Chain : "<<len;

    return 0;
}