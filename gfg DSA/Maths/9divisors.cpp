//All divisor of a no.
//T.C. Theta(sqrt(n))
//S.C. O(#divisors)

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

void divisors(int n) {                              //Naive soln.   T.C. theta(n)    S.C. O(1)
    for(int i = 1; i<=n ; i++){
        if(n%i ==0)
            cout<<i<<" ";
    }
}

vector<int> divisors_optimized(int n) {             //Optimized   T.C. theta(sqrt(n))   S.C. O(#divisors)
    vector<int> res;
    for(int i = 1; i<=sqrt(n) ; i++){
        if(n%i ==0) {
            res.push_back(i);
            int div2 = n/i;
            if(div2 != i)
                res.push_back(div2);
        }
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter a no. : ";
    cin>>n;
    cout<<"\nFollowing are the divisors of n :\t";
    
    // divisors(n);
    
    vector<int> res = divisors_optimized(n);
    //Sorting the obtained vector
    sort(res.begin(), res.end());
    for(auto i = res.begin(); i<res.end(); i++)
        cout<<*i<<" ";
    
    return 0;
}