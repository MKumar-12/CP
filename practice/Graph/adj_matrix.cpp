//Adj. Matrix of a graph [Suitable for dense graph]
//T.C. O(V^2)
//S.C. 

#include<iostream>
#include<array>
using namespace std;
const int n = 1e3;
int adj[n][n];      //Global elements are inintialzed as 0         
    

int main()
{
    int n,m;
    bool direction;
    cout<<"\nEnter no. of vertices : ";
    cin>>n;
    cout<<"\nEnter no. of edges : ";
    cin>>m;
    cout<<"\nGraph directed? 1: yes 0:no \n"; 
    cin>>direction;

    for(int i = 0; i<m; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        cin>>u>>v;
        
        adj[u-1][v-1] = 1;
        
        //dir = 1 -> directed graph
        //dir = 0 -> undirected graph
        if(direction == 0)
            adj[v-1][u-1] = 1;
    }

    cout<<"\n\nAdj. Matrix is as follows : \n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }            

    return 0;
}