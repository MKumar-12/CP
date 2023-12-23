// Finding Missing and repeated no.
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    // n - sized grid
    int n = grid[0].size();
    int x = n * n;
    int total = (x * (x + 1)) / 2;

    set<int> s;

    int a,b;
    for(int i = 0; i < n; i++) {
        for(auto j : grid[i]) {
            if(s.count(j) == 0) {
                s.insert(j);
                total -= j;
            }
            else {
                a = j;
            }
        }
    }

    vector<int> res;
    res.push_back(a);
    res.push_back(total);

    return res;
}

int main()
{
    int temp;
    vector<vector<int>> grid;

    cout<<"\nEnter grid values (-1 to stop) : ";
    while(true) {
        vector<int> row;
        cout<<"\nEnter row values (-1 to stop) : ";
        while(true) {
            cin>>temp;
            if(temp == -1) 
                break;
            
            row.push_back(temp);
        }

        if(row.empty())
            break;
        
        grid.push_back(row);
    }

    vector<int> result = findMissingAndRepeatedValues(grid);
    cout<<"\nRepeated Value : "<<result[0];
    cout<<"\nMissing Value  : "<<result[1];
    return 0;
}


/* 
1 3 -1 
2 2 -1
-1
*/