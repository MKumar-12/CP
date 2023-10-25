// Activity selection prob.

// Given a set of n activities with corresponding start and end time
// and a single tasking m/c
// We have to output the max. no. of acitivites that can occur w/o overlapping.

//T.C.  O(n logn)
//S.C. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare_second(pair<int,int> &a , pair<int,int> &b){
    return a.second < b.second;
}

int max_act(vector<pair<int,int>> activities, int n) {
    int ctr = 1;

    //1st activity will always be the part of the result.
    pair<int,int> top = activities.front();
    for(int i = 1; i < n; i++)
    {
        if(top.second <= activities[i].first){
            ctr += 1;
            top.second = activities[i].second;
        }

    }
    return ctr;
}

int main()
{
    int n;
    cout<<"\nEnter no. of activities : ";       //  4
    cin>>n;

    int s,e;
    cout<<"\nPls add the start and end time of activities : ";
    vector<pair<int,int>> activities;
    for(int i = 0; i < n; i++){
        cout<<"\nActivity "<<i+1<<" : ";          
        // 3 8 2 4 1 3 10 11
        cin>>s>>e;
        activities.push_back(make_pair(s,e));;
    }

    //sorting the values based on their finish time
    sort(activities.begin(), activities.end(), compare_second);

    cout<<"\n\nActivities after sorting based on earliest finish times are as follows :"<<endl;
    for(auto i : activities)
        cout<<"("<<i.first<<", "<<i.second<<"), ";


    //Applying greedy algo.
    cout<<"\n\nMax. no. of activities that can be performed {SINGLE TASKING} : "<<max_act(activities, n);
    return 0;
}