// Employee working on longest task
//T.C. O(n)
//S.C. O(1)                 added uptime vector for debugging purpose

#include<bits/stdc++.h>
using namespace std;

int hardestWorker(int n, vector<vector<int>>& logs) {
    int min_id, max_time = -INT_MAX, f_time = 0;

    vector<int> uptime;
    for(int i = 0; i < logs.size(); i++) {
        int crr_time = logs[i][1] - f_time;
        uptime.push_back(crr_time);
        f_time = logs[i][1];

        if(crr_time > max_time) {
            max_time = crr_time;
            min_id = logs[i][0];
        }
        else if(crr_time == max_time) 
            min_id = min(min_id, logs[i][0]);
    }

    cout<<"\nTime required for completion of various tasks is as follows (IDs in lower line): "<<endl;
    for(auto i : uptime) 
        cout<<i<<" ";

    cout<<endl;    
    for(auto i : logs)
        cout<<i[0]<<" ";
      
    return min_id;
}

int main()
{
    int n,tasks;
    cout<<"\nNo. of employees : ";
    cin>>n;

    cout<<"\nEnter no. of tasks : ";
    cin>> tasks;

    vector<vector<int>> logs;
    cout<<"\nEnter the employee id and leave time for completions of tasks : "<<endl;
    for(int i = 0; i < tasks; i++) {
        int id, leave_time;
        cin>>id>>leave_time;

        logs.push_back({id, leave_time});
    }

    int res = hardestWorker(n,logs);
    cout<<"\n\nID of employee with longest task : "<<res;

    return 0;
}

/*
26
4
1 1
3 7
2 12
7 17

*/