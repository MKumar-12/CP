// Finding Sqrt of a no. without any in-built fn.
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using Binary Search 
    int mySqrt(int x) {
        long long int beg = 0, end = x, mid;
        long long int sq;
        int ctr = 1;
        while(beg+1 < end) {
            cout<<"\nPass "<<ctr;
            cout<<"\nBeg : "<<beg;
            cout<<"\nEnd :"<<end;
            cout<<endl;

            mid = (beg + end)/2;
            sq = mid*mid;

            if(sq == x)
                return mid;

            else if(sq < x)
                beg = mid;
            else
                end = mid;
            
            ctr++;
        }

        return beg;
    }
};

int main()
{
    Solution s;
    int n;
    cout<<"\nEnter a no. : ";
    cin>>n;
    cout<<"\nSqrt of a the given no. (to the closest int.) : "<<s.mySqrt(n)<<endl;

    return 0;
}