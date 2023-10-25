//Job Schedulling 

/*
    Given a list of n jobs/processes, 
        along with their profit and deadline.
    
    We get profit associated with a job, only if we complete it within its deadline.

    Only 1 job can be scheduled to CPU at a time.
    Time starts at 0.


    We have to schedule jobs in such a way that we can maximize the profit.

*/

//T.C.  O(n logn)
//S.C. 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//custom comparator fn.
//  1st we compare for deadline,    earliest DL process to appear 1st in list
//  if DL same for 2 processes, 
//    we then compare for their profit. 
bool mycomp(pair<int,int> &a, pair<int,int> &b)
{
    if(a.second == b.second)            // DL same
        return a.first > b.first;       // return 1 with higher profit
    
    return (a.second < b.second);       // DL !same,    return 1 with lower DL 
}


float calc_max_profit(vector<pair<int,int>> profit_deadline) {
    float res = profit_deadline[0].first;           //assign the 1st job to list + update ctr to 1
    int ctr = 1;

    for(int i = 1; i<profit_deadline.size(); i++){
        if(profit_deadline[i].second > ctr){        // find a next suitable job with max_profit
            res += profit_deadline[i].first;
            ctr++;                                  // update the slot.
        }
    }
    
    return res;
}

int main()
{
    int n;
    cout<<"\nEnter the no. of jobs: ";          //  4   5
    cin>>n;

    int profit, dl;
    vector<pair<int,int>> profit_deadline;
    cout<<"\nEnter Profit and deadline for all processes :";
    for(int i = 0; i<n; i++){
        cout<<"\nProcess "<<i+1<<" : ";
        //  70 4 80 1 30 1 100 1                        170
        //  50 2 60 2 20 3 30 3                         140
        //  100 2 50 1 10 2 20 1 30 3                   180
        cin>>profit>>dl;
        profit_deadline.push_back(make_pair(profit,dl));
    }

    sort(profit_deadline.begin(), profit_deadline.end(), mycomp);
    cout<<"\n\nFollowing are the Jobs ordered based on earliest Deadline & in reqd. Pr. :"<<endl;
    for(auto i : profit_deadline)
        cout<<"("<<i.first<<", "<<i.second<<"), ";
    

    cout<<"\n\nFollowing is the max. achieveable profit : "<<calc_max_profit(profit_deadline);
    return 0;
}