#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q; 
    cout<<"Enter n, q :\t";
    cin>> n >> q;
    vector<int> lines[n+q];
   
    for(int i = 0; i < n; i++){
        int len;
        cout<<"\nEnter size of sub-arr "<< i+1 << ": \t";
        cin>> len;
        cout<<"Enter its elements :\t";
        for (int m = 0; m < len; m++){
            int input;
            cin>> input;
            lines[i].push_back(input);
        }
    }
    for (int j = 0; j < q; j++){
        int q1, q2;
        cout<<"\n\nQuery no. "<< j+1 <<" n reqd kth element of that subarray :";
        cin>> q1>> q2;
        cout<<"Reqd element : "<<lines[q1][q2];
    }

    
    // for (auto elem : lines) {
    //     cout<< elem << " ";
    // }
 
    // cout << endl;

    // copy(lines.begin(),
    //      lines.end(),
    //      ostream_iterator<int>(cout, " "));

    cout<<"\n\nAll elements :\n";
    for(int i = 0; i < n; i++){
        for (int m = 0; m < lines[i].size(); m++){
            cout<< lines[i][m]<<" ";
        }
        cout<<endl;
    }            
    
    return 0;
}