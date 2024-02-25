// No. of submatrices that sum to given target(k)
//T.C.
//S.C. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> prefixS(rows, vector<int>(cols,0));
        
        //base cummulative along 1st row n col of matrix :
        prefixS[0][0] = matrix[0][0];
        for(int i = 1; i < rows; i++) {
            prefixS[i][0] += (prefixS[i-1][0] + matrix[i][0]);
        }
        for(int j = 1; j < cols; j++) {
            prefixS[0][j] += (prefixS[0][j-1] + matrix[0][j]);
        }

        //calc. Prefix sum along both axis
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                prefixS[i][j] = prefixS[i-1][j] + prefixS[i][j-1] - prefixS[i-1][j-1] + matrix[i][j];
            }
        }

        cout<<"\n\nPrefix sum matrix : "<<endl;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout<<prefixS[i][j]<<" ";
            }
            cout<<endl;
        }

        int ctr = 0;
        // Brute force O(n^4)
        for(int y1 = 0; y1 < rows; y1++) {
            for(int y2 = y1; y2 < rows; y2++) {
                for(int x1 = 0; x1 < cols; x1++) {
                    for(int x2 = x1; x2 < cols; x2++) {
                        //sum of elements in matrix formed by coord : [y1...y2][x1...x2]
                        int sum = prefixS[y2][x2] - (x1 > 0 ? prefixS[y2][x1-1] : 0) - (y1 > 0 ? prefixS[y1-1][x2] : 0) + (x1 > 0 && y1 > 0 ? prefixS[y1-1][x1-1] : 0);
                    
                        if(sum == target)
                                ctr++;
                    }
                }
            }
        }
        
        return ctr;
    }
};

int main()
{
    int k, m, n;
    cout<<"\nEnter no. of rows n column : ";
    cin>>m>>n;
    // 5 6

    vector<vector<int>> matrix(m, vector<int>(n,0));
    cout<<"\nEnter values : "<<endl;
    // 0 1 1 1 0 1 0 0 0 0 0 1 0 0 1 0 0 1 1 1 0 1 1 0 1 0 0 1 0 0 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin>>temp;
            matrix[i][j] = temp;
        }
    }

    Solution S;
    cout<<"\nEnter target value : ";
    cin>>k;
    // 0

    cout<<"\nNumber of Sub-matrices that sum to target : "<<S.numSubmatrixSumTarget(matrix, k);
    return 0;
}


/*
0 1 0           0 1 1
1 1 1           1 3 4
0 1 0           1 4 5
*/