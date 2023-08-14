//
//

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    vector<unordered_map<int,int> > A;
    int snap_id = -1;
    SnapshotArray(int length) {
        A.clear();
        A = vector<unordered_map<int,int> >(length);
    }
    
    void set(int index, int val) {
        A[index][snap_id] = val;
    }
    
    int snap() {
        snap_id++;
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        int temp = snap_id - 1;
        while(temp >= -1){
            if(A[index].find(temp) == A[index].end())
                temp--;
            else
                return A[index][temp];   
        }
        return 0;
    }
};

int main()
{
    int len;
    cout<<"\nEnter length : ";
    cin>>len;
    SnapshotArray sA= new SnapshotArray(len);
    sA.snap();
    cout<<"done";
    return 0;
}