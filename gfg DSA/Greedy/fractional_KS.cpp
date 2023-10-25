//Fractional Knapsack Prob.

// for a given CAPACITY, we'll pick itemsets based on higher val/wt ratio
// itemsets can be taken completely/partially for the requirement.

//T.C.  O(n logn) 
//S.C. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// custom comparator for pair
bool mycomp(pair<int,int> &a, pair<int,int> &b) {
    float r1 = a.second/a.first;
    float r2 = b.second/b.first;

    return r1 > r2;
}


//Greedy Algo.
float calc_max_val(vector<pair<int,int>> wt_val, int cap){
    float res = 0;
    for(auto i : wt_val){
        if(i.first <= cap) {                        //itemset taken completely 
            cap -= i.first;
            res += i.second;
        }
        else {                                      //itemset taken partially 
            res += (i.second * cap) / i.first;
            break;              //must be the last itemset taken partially, that'll fill CAP
        }
    }
    return res;
}

int main()
{
    int n;
    vector<pair<int,int>> wt_val;
    cout<<"\nEnter the no. of Items present : ";       //  3
    cin>>n;
    
    int wt,val,ratio;
    cout<<"\nEnter the wt. and value for each item : "<<endl;      
    //  30 120 20 100 10 60
    for(int i = 0; i < n ; i++){
        cout<<"\nItemset "<<i+1<<" : ";
        cin>>wt>>val;
        wt_val.push_back(make_pair(wt,val));
    }

    sort(wt_val.begin(), wt_val.end(), mycomp);

    cout<<"\n\nItemsets sorted in decreasing order of their Val/wt ratio are as follows : "<<endl;
    for(auto i : wt_val)
        cout<<"("<<i.first<<", "<<i.second<<"), ";

    int cap;
    cout<<"\n\nKnapSack Capacity : ";               //  50
    cin>>cap;
    
    cout<<"\n\nThen, Max. achieveable Val. : "<<calc_max_val(wt_val, cap);
    return 0;
}