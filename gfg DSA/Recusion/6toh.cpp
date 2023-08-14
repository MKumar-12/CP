//Tower of Hanoi
//move disks s.t. NO LARGER disk over smaller.
//T(n) = 2T(n-1) + 1
//#MOVEMENTS = 2^n - 1
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

//Initially A = n, B = C = 0;
//At end, A = B = 0, C = n;
void tower_of_hanoi(int n,char BEG = 'A', char AUX = 'B', char END = 'C') {
    if(n == 1){
        //if only 1 disk exists,
        //move it from BEG --> END
        cout<<"\nMove disk "<<n<<" from "<<BEG<<" to "<<END;
        return;
    }
    
    //move n-1 disks from BEG --> AUX using END
    tower_of_hanoi(n-1,BEG,END,AUX);
    //move last disk from BEG --> END
    cout<<"\nMove disk "<<n<<" from "<<BEG<<" to "<<END;
    //move n-1 disks from AUX --> END using BEG
    tower_of_hanoi(n-1,AUX,BEG,END);
}

int main()
{
    int n;
    cout<<"\nEnter the no. of disks in A : ";
    cin>>n;
    cout<<"\nSteps required to swap disks from A to C : \n\n";
    tower_of_hanoi(n);
    return 0;
}