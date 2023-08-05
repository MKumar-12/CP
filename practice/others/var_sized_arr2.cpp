#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void calculate(vector<vector<int>> inputArrays, vector<pair<int,int>> queries){
    int numOfQueries = queries.size();
    for(int i=0;i<numOfQueries;i++)
    {
        int arrayNum=queries[i].first;
        int arrayIdxPos=queries[i].second;
        
        cout<<inputArrays[arrayNum][arrayIdxPos]<<endl;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n=0,q=0;
    cin>>n>>q;
    vector<vector<int>> inputArrays;
    for(int i=0;i<n;i++){
        vector<int> tp1;
        int sizeArray=0;
        cin>>sizeArray;
        for(int j=0;j<sizeArray;j++){
            int val2;
            cin>>val2;
            tp1.push_back(val2);
        }
        inputArrays.push_back(tp1);
    }
    
    vector<pair<int,int>> queries;
    for(int i=0;i<q;i++){
        int firstVal,secondVal;
        cin>>firstVal;
        cin>>secondVal;
        pair<int,int> t2;
        t2.first=firstVal;
        t2.second=secondVal;
        queries.push_back(t2); //queries.push_back({firstVal,secondVal})
    }
    
    calculate(inputArrays,queries);
    
    return 0;
}
