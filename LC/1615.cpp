//Maximal Network connectivity
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        vector<int,vector<int>> adjList;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjList[u].push_back(v);

            if(dir == 0)
                adjList[v].push_back(u);
        }

        //printing adj. list
        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adjList) {
                cout<< i.first<< "-> ";

                for(auto j:i.second)
                    cout<<j<<", ";
                
                cout<<endl;
            }
        }

        //Driver fn.
        int calc_rank() {
            return maximalNetworkRank(n, adjList);
        }


        int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int max_rank = 0;
        vector<int> adj[99];

        //creating adjacency list
        for(int i = 0; i< roads.size(); i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        //for each pair, computing max connectivity
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int total_roads = 0;
                bool direct_conn = false;

                for(int neighbour = 0; neighbour < adj[i].size(); neighbour++) {
                    if(adj[i][neighbour] == j)
                        direct_conn = true;
                }

                total_roads = adj[i].size() + adj[j].size();

                if(direct_conn)
                    total_roads--;
                
                max_rank = max(max_rank, total_roads);
            }
        }

        return max_rank;
    }
};

int main()
{
    Graph g;
    // bool direction;
    cout<<"\nEnter no. of vertices and edges : ";
    cin>>n>>e;
    // cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    // cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    g.calc_rank();
    cout<<"\nMaximal n/w rank is : ";

    cout<<"\n\nBtw vertices : "<<" ";
    
    return 0;
}